#include <algorithm>
#include <climits>
#include <cstring>
#include <cctype>
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

const int64_t mod = 1e9 + 7;
const int cap = 1e5 + 1;
char d;
int K[cap];
int D;
int dp[cap][100];

void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int main() {
    int l = 0;
    for (; scanf("%c", &d) && isdigit(d); ++l)
        K[l] = d - '0';
    scanf(" %d", &D);

    fill(&dp[0][0], &dp[0][0] + cap * 100, 0);
    dp[0][0] = 1;
    for (int i = 1; i < l; ++i)
        for (int j = 0; j < D; ++j)
            for (int k = 0; k < 10; ++k)
                add(dp[i][(j + k) % D], dp[i - 1][j]);

//     for (int i = 0; i < l; ++i) {
//         for (int j = 0; j < D; ++j)
//             printf("%d ", dp[i][j]);
//         printf("\n");
//     }

    int ans = dp[l - 1][0] - 1, tot = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = int(i == 0); j < K[i]; ++j) {
            add(ans, dp[l - 1 - i][(2 * D - tot - j) % D]);
        }
        tot = (tot + K[i]) % D;
    }
    add(ans, int(tot == 0));

    printf("%d\n", ans);
}



