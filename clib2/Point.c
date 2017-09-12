#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

/* Static counter used for initializing new points */
static int counter = 0;

/* display a Point value */
void showPoint(Point point) {
    printf("Point in C      is (%d, %d)\n", point.x, point.y);
}

/* display a Point passed by reference */
void showPointRef(Point *point) {
    printf("Point in C      is (%d, %d)\n", point->x, point->y);
}

/* Increment a Point which was passed by value */
void movePoint(Point point) {
    printf("Point in C      is (%d, %d)\n", point.x, point.y);
    point.x++;
    point.y++;
    printf("Point in C      is (%d, %d)\n", point.x, point.y);
}

/* Increment a Point which was passed by reference */
void movePointRef(Point *point) {
    printf("Point in C      is (%d, %d)\n", point->x, point->y);
    point->x++;
    point->y++;
    printf("New point in C  is (%d, %d)\n", point->x, point->y);
}

/* Return by value */
Point getPoint(void) {
    Point point = { counter++, counter++};
    printf("Returning Point    (%d, %d)\n", point.x, point.y);
    return point;
}

/* Return by reference */
Point* getPointPointer(void) {
    Point* point = malloc(sizeof(Point));
    point->x = counter++;
    point->y = counter++;

    printf("Returning Point    (%d, %d) at %p\n", point->x, point->y, point);
    return point;
}

/* Free a point allocated by getPointPointer */
void freePointPointer(Point *point) {
    printf("Freeing Point      (%d, %d) at %p\n", point->x, point->y, point);
    free(point);
}