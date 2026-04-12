#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string k; int d;
    cin >> k >> d;
    int n = k.length();
    ll dp[n+1][d] = {};
    dp[0][0] = 1;
    for(int m = 1; m <= n; m++)
        for(int x = 0; x < d; ++x)
            for (int i = 0; i <= 9; i++)
                dp[m][x] = (dp[m][x] + dp[m-1][((x-i)%d+d)%d]) % mod;
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k[i]-'0'; ++j) {
            ans = (ans + dp[n-i-1][((-sum-j)%d+d)%d])%mod;
        }
        sum = (sum + k[i]-'0') % d;
    }
    if(sum % d == 0)
        ans = (ans + 1)%mod;
    ans = (ans - 1) % mod;
    cout << (ans+ mod) % mod;
    return 0;
}
