#include "points_segments.h"

int compare(const void *point1, const void *point2) {
    const int *coord1 = *(const int **)point1;
    const int *coord2 = *(const int **)point2;
    if (coord1[0] == coord2[0]) {
        if (coord1[1] == 0) { //coord1 is a point
            if (coord2[1] == 1) { //coord2 is a start
                return 1;
            }
            return -1; //coord2 is an end
        }
        //coord2 is a point
        if (coord1[1] == 1) { //coord1 is a start
            return -1;
        }
        return 1; //coord1 is an end
    }
    return coord1[0] - coord2[0];
}

int **points_segments_sorted(int **segments, int s, int *points, int p) {
    int **results = malloc(sizeof(int*) * p);
    for (int g = 0; g < p; g++) {
        results[g] = malloc(sizeof(int) * 2);
    }

    int **all_points = malloc(sizeof(int*) * (2 * s + p));
    for (int h = 0; h < 2 * s + p; h++) {
        all_points[h] = malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < p; i++) { //points
        all_points[i][0] = points[i];
        all_points[i][1] = 0;
    }
    for (int j = p; j < s + p; j++) { //segment starts
        all_points[j][0] = segments[j - p][0];
        all_points[j][1] = 1;
    }
    for (int k = s + p; k < 2 * s + p; k++) { //segment ends
        all_points[k][0] = segments[k - p - s][1];
        all_points[k][1] = 2;
    }

    qsort(all_points, 2 * s + p, sizeof(all_points[0]), compare);

    int count = 0;
    int res = 0;
    for (int l = 0; l < 2 * s + p; l++) {
        if (all_points[l][1] == 0) { //point
            results[res][0] = all_points[l][0];
            results[res][1] = count;
            res++;
        }
        else if (all_points[l][1] == 1) { //segment start
            count++;
        }
        else { //segment end
            count--;
        }
    }

    return results;
}
