CC = gcc
CFLAGS = -Wall -std=c99

all: test

points_segments_naive.o: points_segments_naive.c points_segments.h
	$(CC) $(CFLAGS) -c points_segments_naive.c

points_segments_sorted.o: points_segments_sorted.c points_segments.h
	$(CC) $(CFLAGS) -c points_segments_sorted.c

test.o: test.c points_segments.h
	$(CC) $(CFLAGS) -c test.c

test: points_segments_naive.o test.o
	$(CC) $(CFLAGS) -o test points_segments_naive.o test.o

clean:
	rm *.o test
