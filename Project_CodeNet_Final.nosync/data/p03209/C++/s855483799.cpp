#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

#define MAX_N 50

using namespace std;


long int L[MAX_N];
long int P[MAX_N];

long int rec(long int N, long int X) {
    if (N == 0) return X == 1 ? 1 : 0;
    if (X == 1) return 0;
    if (X <= 1 + L[N - 1]) return rec(N - 1, X - 1);
    if (X == 2 + L[N - 1]) return P[N - 1] + 1;
    if (X <= 2 + 2 * L[N - 1]) return P[N - 1] + 1 + rec(N - 1, X - L[N - 1] - 2);
    if (X == L[N]) return 2 * P[N - 1] + 1;
    else {
        return -1;
    }
}

int main() {

    long int N, X;

    scanf("%ld %ld", &N, &X);
    L[0] = 1;
    P[0] = 1;
    for (int i = 1; i <= N; i++) {
        L[i] = 2 * L[i-1] + 3;
        P[i] = 2 * P[i-1] + 1;
    }

    printf("%ld\n", rec(N, X));

    return 0;
}