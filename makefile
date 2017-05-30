airlineflight: main.o
	gcc main.o -o airlineflight
main.o: main.c
	gcc -c main.c
clean:
	rm -f *.o core
