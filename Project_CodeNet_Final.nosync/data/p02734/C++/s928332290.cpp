#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)998244353, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, s, i, j, a[3003], dp[3003][3003] = {}, ans;

    scanf("%d%d", &n, &s);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    for (i = 0; i < n; i++) for (j = 0; j <= s; j++) {
        if (j == 0) {
            dp[i + 1][j] = dp[i][j] + 1;
        }
        else {
            dp[i + 1][j] = dp[i][j];
            if (j >= a[i]) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - a[i]]) % mod;
            if (j == a[i]) dp[i + 1][j] = (dp[i + 1][j] + 1) % mod;
        }
    }

    ans = 0;
    for (i = 1; i <= n; i++) {
        ans = (ans + dp[i][s]) % mod;
    }

    printf("%d\n", ans);

    return 0;
}