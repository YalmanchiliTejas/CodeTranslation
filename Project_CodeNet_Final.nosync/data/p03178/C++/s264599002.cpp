#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 +7;
const int maxn = 10010;

char k[maxn];

int main()
{
    scanf("%s", k);
    int d;
    scanf("%d", &d);
    int n = strlen(k);
    vector<vector<ll>> dp(d, vector<ll>(2));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        vector<vector<ll>> new_dp(d, vector<ll>(2));
        for (int sum = 0; sum < d; sum++){
            vector<bool> v = {0, 1};
            for (bool smaller : v){
                for (int digit = 0; digit < 10; digit++){
                    if (digit > k[i] - '0' && !smaller){
                        break;
                    }
                    new_dp[(sum + digit) % d][smaller || (digit < k[i] - '0')] =
                            (new_dp[(sum + digit) % d][smaller || (digit < k[i] - '0')] + dp[sum][smaller]) % mod;
                }
            }
        }
        dp = new_dp;
    }
    ll ans = (dp[0][0] + dp[0][1]) % mod;
    ans = (ans - 1 + mod) % mod;
    cout << ans;
    return 0;
}
