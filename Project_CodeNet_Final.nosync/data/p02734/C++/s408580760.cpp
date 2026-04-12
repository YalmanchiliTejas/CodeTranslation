#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
const ll mod = 998244353;

ll MOD (ll a) {
    if (a < 0)
        a += mod;
    return (a % mod);
}

int n, s;
ll a[3004];
ll dp[3004][3004][4];

ll go (int i, int sum, int st) {
    if (sum > s)
        return 0;
    if (st == 2) {
       // cout << i << " " << sum << endl;
        if (sum == s)
            return 1;
        return 0;
    }
    if (i == n) {
        return 0;
    }
    if (dp[i][sum][st] != -1)
        return dp[i][sum][st];
    ll ans = 0;
    if (st == 0)
        ans = MOD(MOD(ans + go (i+1, sum, st)) + go (i, sum, 1));
    else if (st == 1)
        ans = MOD(ans + MOD(go(i+1, sum, 1) + MOD(go(i+1, sum+a[i], 1) + MOD(go(i, sum, 2) + go(i, sum+a[i],2)))));
    dp[i][sum][st] = ans;
    return ans;
}

void testCase() {
    cin >> n >> s;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<=3001; i++) {
        for (int j=0; j<=3001; j++) {
            for (int k=0; k<4; k++)
                dp[i][j][k] = -1;
        }
    }
    cout << go (0, 0, 0) << endl;     
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}