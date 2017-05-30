//Alec Arroyo
//contains all #includes that are used for the program
#include "header.h"

#define RECORD 100
#define BINFILE "test.bin"

int main (int argc, char *argv[])
{
  FILE *fptr;
  int ans = 1;
  FlightInfo f;
  FlightInfo g;
  FlightInfo setup;
  FlightInfo prin;
  int j, h;
  int count = 0;
  int infoc = 0;
  int aircount = 0;
  f.quit = 0;
  f.stat = 0;
  
 //Initialize code/ temp records 
  strcpy(setup.airlinecode, "1");
  strcpy(setup.origincode, "1");
  strcpy(setup.destincode, "1");
  strcpy(setup.month, "1");
  strcpy(setup.week, "1");
  strcpy(setup.day, "1");
  strcpy(setup.time, "1");
  strcpy(setup.year, "1");
  
  //open file
  if ((fptr = fopen(BINFILE, "r+")) == NULL) {
    fprintf(stderr, "Could not open file: %s\n", BINFILE);
    exit(1);
  }
  
  //place temp records to be replaced later
  for (h = 0; h < RECORD ; h++)
  {
    fwrite((const void *) &setup, sizeof(FlightInfo), 1, fptr);
  }
  
  //When user inputs -1 end while
  while(f.quit != -1)
  { 
    printf("Enter info about the Air Flight: "); fflush(stdout);
    scanf("%s %s %s %s %s %s %s %s", f.airlinecode, f.origincode, f.destincode, f.month, f.week, f.day, f.time, f.year);
      
      
      if(count == 0)
      {
        strcpy(g.airlinecode, f.airlinecode);
        strcpy(g.origincode, f.origincode);
      }
      
      //updates
      if (f.quit != -1)
      {
        update_db(fptr, &f);
        count++;
        //FlightInfo f;
      }
      f.stat = f.stat + 1;
      //ignore
      if(strcmp(g.airlinecode, f.airlinecode) == 0)
      {
        if(strcmp(g.origincode, f.origincode) == 0)
        {
          aircount++;
        }
      }
      
      //Checks to see if you would like ot continue
      printf("Do you want to continue? (0 for yes/ -1 for no) \n");
      scanf("%d", &f.quit);
      
  }
  
  //rewinds back to the begining
  rewind(fptr);
  
  //Prints the records
  for(j = 0; j < count; j++)
  {
    fread((void *) &f, sizeof(FlightInfo), 1, fptr);

    fprintf(stderr, "%s %s %s %s %s %s %s %s\n", f.airlinecode, f.origincode, f.destincode, f.month, f.week, f.day, f.time, f.year);  
  }
     //printf number of airlines
    printf("Number of airlines for a given airport: %d\n", aircount);
  
  //closes file
  if(fclose(fptr) == EOF)
  {
    fprintf(stderr, "Could not close file: \n", BINFILE);
  }
  
  return 0;
}

//updates the file
void update_db(FILE *fptr, FlightInfo *flight)
{
  fseek(fptr, (flight->stat)*sizeof(FlightInfo), SEEK_SET);
  
  fwrite((const void *) flight, sizeof(FlightInfo), 1, fptr);
}