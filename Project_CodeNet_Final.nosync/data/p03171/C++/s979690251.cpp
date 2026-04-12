#include <bits/stdc++.h>
using namespace std;
long long dp[3000][3000][2], cs[3000];
int a[3000];
long long calc(int l, int r, bool turn)
{

    int t = a[l];
    if(l==r) return t;

    if(dp[l][r][turn] != -1) return dp[l][r][turn];

    long long seg = cs[r] - (l?cs[l-1]:0);
    long long A = seg - calc(l+1, r, turn^1), b = seg - calc(l, r-1, turn^1);
    dp[l][r][turn] = max(A, b);
    return dp[l][r][turn];


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3000; ++i) {
        memset(dp[i], -1, sizeof(dp[i]));
    }
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cs[i] = a[i] + cs[i- bool(i)];
    }
    cout << 2*calc(0, n-1, 1) - cs[n-1];
    return 0;
}