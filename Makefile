CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99
LDFLAGS=-lm

graphy: main.o graphmath.o
    $(CC) main.o graphmath.o $(LDFLAGS) -o graphy

main.o: main.c graphmath.h
    $(CC) -c main.c $(CFLAGS) -o main.o

graphmath.o: graphmath.c graphmath.h
    $(CC) -c graphmath.c $(CFLAGS) -o graphmath.o

clean:
    rm -f ./*.o
