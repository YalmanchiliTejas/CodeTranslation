#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

#include <chrono>

#define INF 1e9
#define nmax 200010
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)(x.size()))

#define MOD 1000000007

#define MOD1 998244353
#define MOD2 666013
#define P1 255
#define P2 2059

using namespace std;
using namespace std::chrono;

typedef pair<int, int> pii;
typedef long long int ll;

int n, s;
int a[3010], dp[3010][3010][3];

int f(int x)
{
    if (x >= MOD1) return x - MOD1; else
        return x;
}

int main()
{
    scanf("%d %d", &n, &s);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    dp[0][0][0] = 1;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++) {

            dp[i + 1][j][0] = f(dp[i + 1][j][0] + dp[i][j][0]);
            dp[i + 1][j][1] = f(dp[i + 1][j][1] + f(dp[i][j][0] + dp[i][j][1]));
            dp[i + 1][j][2] = f(dp[i + 1][j][2] + f(f(dp[i][j][0] + dp[i][j][1]) + dp[i][j][2]));

            if (j + a[i + 1] <= s) {

                dp[i + 1][j + a[i + 1]][1] = f(dp[i + 1][j + a[i + 1]][1] + f(dp[i][j][0] + dp[i][j][1]));
                dp[i + 1][j + a[i + 1]][2] = f(dp[i + 1][j + a[i + 1]][2] + f(dp[i][j][0] + dp[i][j][1]));
            }
        }

    printf("%d", dp[n][s][2]);

    // IMPORTANT!!!!!
    // Are you missing something????
    // check limits, int or ll

    return 0;
}