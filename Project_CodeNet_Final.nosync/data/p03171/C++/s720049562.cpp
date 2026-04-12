#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e3 + 5, mod = 1e9 + 7;
int n, c[maxn][maxn], a[maxn];
long long f[maxn][maxn];

long long dp(int l, int r)
{
    if (l > r) return 0;
    long long &res = f[l][r];
    if (c[l][r]) return res;
    c[l][r] = true;
    int turn = (l + (n - r + 1)) % 2;
    if (turn) {
        res = 1e13;
        res = min(dp(l + 1, r) - a[l], res);
        res = min(dp(l, r - 1) - a[r], res);
    } else {
        res = -1e13;
        res = max(dp(l + 1, r) + a[l], res);
        res = max(dp(l, r - 1) + a[r], res);
    }
    return res;
}

int main()
{
    #ifdef NTMA 
        freopen("abc.inp", "r", stdin);
    #endif
    //memset(f, 255, sizeof(f));
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    cout << dp(1, n);
    return 0;
}