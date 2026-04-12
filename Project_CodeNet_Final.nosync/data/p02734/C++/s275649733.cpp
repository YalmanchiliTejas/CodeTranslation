#include <iostream>

using namespace std;
long long dp[3010][3010],a[3010],mod = 998244353;
int main(){
    int i,j,n,s;
    cin >> n >> s;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(i=1;i<=n;i++){
        for(j=0;j<=s;j++){
            (dp[i][j] += dp[i - 1][j]) %= mod;
            if(j + a[i - 1]>s) continue;
            if(j==0){
                (dp[i][j + a[i - 1]] += i*dp[i - 1][j]%mod) %= mod;
            }else{
                (dp[i][j + a[i - 1]] += dp[i - 1][j]) %= mod;
            }
        }
    }
    long long ans = 0;
    for(i=0;i<=n;i++){
        (ans += dp[i][s]) %= mod;
    }
    cout << ans << endl;
}
