#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<b)return 0; a=b; return 1;}

ll mod = 998244353;
ll dp[3002][3002];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);


    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans = 0;
    for(int i=0;i<n;i++){
        dp[i+1][0] = 1;
        dp[i+1][a[i]] = 1;
        for(int j=0;j<=s;j++){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= mod;
            if(j + a[i] <= s){
                dp[i+1][j+a[i]] += dp[i][j];
                dp[i+1][j+a[i]] %= mod;
            }
        }
        ans = (ans + dp[i+1][s]) % mod;
        //cerr << i << " " << dp[i+1][s] << " " << ans << endl;
    }
    cout << ans << endl;
}