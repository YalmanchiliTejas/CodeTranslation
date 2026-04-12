//
//  main.cpp
//  Exercise
//
//

#include <algorithm>
#include <iostream>
#include <limits>
#include <math.h>
#include <tuple>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "string.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

using int_t = int;

int main() {
    int A, B, C, X, Y;
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    if (A + B <= 2 * C) {
        printf("%d", A * X + B * Y);
    } else if (2 * C <= A && 2 * C <= B) {
        printf("%d", 2 * C * max(X, Y));
    } else if (2 * C <= A) { // and B < 2 * C
        if (X <= Y) {
            printf("%d", 2 * C * X + B * (Y - X));
        } else {
            printf("%d", 2 * C * X);
        }
    } else if (2 * C <= B) { // and A < 2 * C
        if (Y <= X) {
            printf("%d", 2 * C * Y + A * (X - Y));
        } else {
            printf("%d", 2 * C * Y);
        }
    } else {
        if (X >= Y) {
            printf("%d", Y * 2 * C + (X - Y) * A);
        } else {
            printf("%d", X * 2 * C + (Y - X) * B);
        }
    }
    printf("\n");
    return 0;
}