#include <cstdio>
#include <algorithm>
using namespace std;


int A, B, C, X, Y;


int main() {
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

    int cost = 0;
    int k = 2*min(X, Y);
    cost += C * k;
    cost += A * max(X - k/2, 0);
    cost += B * max(Y - k/2, 0);

    int cost2 = 0;
    k = 2*max(X, Y);
    cost2 += C * k;
    cost2 += A * max(X - k/2, 0);
    cost2 += B * max(Y - k/2, 0);
    if(cost2 < cost)
        cost = cost2;

    cost2 = 0;
    k = 0;
    cost2 += A * X;
    cost2 += B * Y;
    if(cost2 < cost)
        cost = cost2;

    printf("%d\n", cost);
    return 0;
}
