#ifndef POINTS_SEGMENTS_H
#define POINTS_SEGMENTS_H

#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size);
void print_array_2D(int **arr, int rows, int cols);
int **points_segments_naive(int **segments, int s, int *points, int p);
int compare(const void *point1, const void *point2);
int **points_segments_sorted(int **segments, int s, int *points, int p);

#endif
