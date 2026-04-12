#include <algorithm>
#include <climits>
#include <cstring>
#include <inttypes.h>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

const int cap = 3002;
int N;
int A[cap];
int64_t dp[cap][cap];


int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf(" %d", &A[i]);
    
    for (int i = 1; i <= N; ++i)
        dp[i][i] = 0;
    for (int span = 1; span <= N; ++span) {
        for (int i = 1; i + span <= N + 1; ++i) {
            int j = i + span;
            if ((span & 1) ^ (N & 1)) {
                dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j - 1]);
            }
            else {
                dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j - 1]);
            }
        }
    }
    printf("%" PRId64 "\n", dp[1][N + 1]);
}









