#include <stdio.h>
#include <algorithm>

using namespace std;

int solve(int A, int B, int C, int X, int Y) {
    int val;

    val = min(A + B, 2 * C) * min(X, Y);
    if (X > Y) {
        val += (X - Y) * min(A, 2 * C);
    }
    else {
        val += (Y - X) * min(B, 2 * C);
    }

    return val;
}

int main(void) {
    int A, B, C, X, Y;

    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

    printf("%d", solve(A, B, C, X, Y));
}