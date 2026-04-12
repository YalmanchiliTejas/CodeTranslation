/*
Author : Xinyuan
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef long long int ll;
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

const int nax = 3005;
ll dp[nax][nax];
int main() {
    int n = nxt();
    VI a(n);
    generate(all(a), nxt);
    // dp[0][n-1]
    for (int L = n - 1; L >= 0; L--) {
        for (int R = L; R < n; R++) {
            if (L == R) dp[L][R] = a[L];
            dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
        }
    }
    printf("%lld\n", dp[0][n - 1]);
    return 0;
}
