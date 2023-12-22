CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: main

main: main.o clothes_db.o
	$(CC) $(CFLAGS) -o main main.o clothes_db.o

main.o: main.c clothes_db.h
	$(CC) $(CFLAGS) -c main.c

clothes_db.o: clothes_db.c clothes_db.h
	$(CC) $(CFLAGS) -c clothes_db.c

clean:
	rm -f *.o main