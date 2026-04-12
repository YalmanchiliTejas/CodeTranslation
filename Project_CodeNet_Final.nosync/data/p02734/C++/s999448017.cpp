#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll a[3005];
ll dp[3005][3005];

int main()
{
    ll n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        for(int j = a[i - 1]; j <= s; j++) dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i - 1]]) % MOD;
        dp[i][a[i - 1]] = (dp[i][a[i - 1]] + i - 1) % MOD;
        ans = (ans + dp[i][s]) % MOD;
    }
    cout << ans << endl;
}