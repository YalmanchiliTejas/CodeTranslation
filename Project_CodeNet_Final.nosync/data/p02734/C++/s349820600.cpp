#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long mod = 998244353;
int n, s;
vector<int> a;
vector< vector< long long > > dp;
int main(void){
    cin >> n >> s;
    a.assign(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];
    dp.assign(n+1, vector<long long>(s+1, 0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            dp[i][j] = dp[i-1][j];
            if(j > a[i]) dp[i][j] += dp[i-1][j-a[i]];
            if(j == a[i]){
                dp[i][j] += i;
            }
            dp[i][j] %= mod;
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    long long ans = 0;
    for(int R=1;R<=n;R++){
        ans += dp[R][s];
        // cout << R << " " << dp[R][s] << endl;
        ans %= mod;
    }
    cout << ans << endl;
}
