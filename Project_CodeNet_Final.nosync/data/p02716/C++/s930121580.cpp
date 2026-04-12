#include <bits/stdc++.h>
#define rep(begin, end) for (i=begin;i<end;i++)
#define init(arr, val) for (i=0;i<end;i++) arr[i] = val;
#define prlong longlong long(i0, i1) prlong longf("%d %d\n", i0, i1)

using namespace std;
const long long inf = pow(10,13);
const int nil = -1;
int i, j, n, m, k, ans;
int a[200001];
long long dp[200001][3];

int main() {
    scanf(" %d", &n);
    rep(1,n+1) scanf(" %d", &a[i]);
    // even; 0: i/2-1, 1: i/2
    // odd ; 0: (i-1)/2, 1: (i+1)/2
    dp[1][0] = 0;
    dp[1][1] = a[1];
    dp[2][0] = 0;
    dp[2][1] = max(a[1], a[2]);
    rep(3, n+1) {
        if (i%2 == 0) {
            dp[i][0] = max(dp[i-2][0] + a[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-2][1] + a[i], dp[i-1][1]);
        } else {
            dp[i][0] = max(dp[i-2][0] + a[i], dp[i-1][1]);
            dp[i][1] = dp[i-2][1] + a[i];
        }
    }
    if (n%2 == 0) printf("%lld\n", dp[n][1]);
    else printf("%lld\n", dp[n][0]);
}