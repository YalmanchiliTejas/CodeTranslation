#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 3005;
const ll mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);
    ll n, s, dp[N] = {0}, a, ans = 0;
    cin >> n >> s;
    for (int i=1; i<=n; i++) {
        cin >> a;
        if (a > s) continue;
        if (a == s) {
            (ans += i*(n-i+1)) %= mod;
            continue;
        }
        for (int j=s-a; j>=1; j--) {
            if (j == s-a) {
                (ans += dp[s-a]*(n-i+1)) %= mod;
            }
            (dp[j+a] += dp[j]) %= mod;
        }
        dp[a] += i;
    }
    cout << ans;
    return 0;
}
