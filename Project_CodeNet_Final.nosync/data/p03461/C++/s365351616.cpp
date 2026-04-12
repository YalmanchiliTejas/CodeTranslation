// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

const int INF = numeric_limits<int>::max();

constexpr int MAX_N = 105;

int A, B, D[11][11];

int F[MAX_N][MAX_N];

int main() {
    cin >> A >> B;
    for (int j = 0; j < A; ++j) {
        for (int k = 0; k < B; ++k) {
            cin >> D[j][k];
        }
    }

    for (int j = 0; j < MAX_N; ++j) for (int k = 0; k < MAX_N; ++k) {
        for (int a = 0; a < A; ++a) for (int b = 0; b < B; ++b) {
            F[j][k] = max(F[j][k], D[a][b] - (a+1) * j - (b+1) * k);
        }
    }

    for (int a = 0; a < A; ++a) for (int b = 0; b < B; ++b) {
        int min_dist = INF;
        for (int j = 0; j < MAX_N; ++j) {
            for (int k = 0; k < MAX_N; ++k) {
                min_dist = min(min_dist, (a+1) * j + (b+1) * k + F[j][k]);
            }
        }
        if (min_dist != D[a][b]) {
            printf("Impossible\n");
            return 0;
        }
    }

    printf("Possible\n%d %d\n", 2*MAX_N, 2*(MAX_N-1) + MAX_N*MAX_N);
    for (int j = 0; j < MAX_N-1; ++j) {
        printf("%d %d X\n", (j+1), (j+2));
    }
    for (int j = 0; j < MAX_N-1; ++j) {
        printf("%d %d Y\n", MAX_N+(j+1), MAX_N+(j+2));
    }
    for (int j = 0; j < MAX_N; ++j) {
        for (int k = 0; k < MAX_N; ++k) {
            printf("%d %d %d\n", (j+1), 2*MAX_N-k, F[j][k]);
        }
    }
    printf("%d %d\n", 1, 2*MAX_N);
    return 0;
}
