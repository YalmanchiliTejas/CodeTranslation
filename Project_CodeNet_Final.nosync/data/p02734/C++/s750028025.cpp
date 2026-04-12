#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll U=3010;
    ll MOD=998244353;
    ll n,s;cin>>n>>s;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(s+1,0));
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <s+1; ++j) {
            ll cost=(j==0)?1:0;
            dp[i+1][j]+=(dp[i][j]+cost)%MOD;
            dp[i+1][j]%=MOD;
            if(j+a[i]>s)continue;
            dp[i+1][j+a[i]]+=(dp[i][j]+cost)%MOD;
            dp[i+1][j+a[i]]%=MOD;
        }
        ans+=dp[i+1][s];
        ans%=MOD;
//        cout <<ans <<endl;
    }
    cout <<ans <<endl;
    return 0;
}