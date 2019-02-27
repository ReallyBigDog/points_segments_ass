#include "points_segments.h"

int **points_segments_naive(int **segments, int s, int *points, int p) {
    int **results = malloc(sizeof(int*) * p);
    for (int h = 0; h < p; h++) {
        results[h] = malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < p; i++) {
        results[i][0] = points[i];
        results[i][1] = 0;
        for (int j = 0; j < s; j++) {
            if (segments[j][0] <= points[i] && points[i] <= segments[j][1]) {
                results[i][1]++;
            }
        }
    }
    return results;
}
