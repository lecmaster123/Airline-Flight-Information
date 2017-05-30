//Alec Arroyo
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h> 

//Global Struct 
struct flightstuff
{
  int quit;
  int stat;
  char airlinecode[100];
  char origincode[100];
  char destincode[100];
  char month[100];
  char week[100];
  char day[100];
  char time[100];
  char year[100];
};
typedef struct flightstuff FlightInfo;

//Prototype
void update_db(FILE *, FlightInfo*);