#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans = 0;
const ll MOD = 998244353;
void Main(){
    ll n;cin>>n;
    ll s;cin>>s;
    vector<ll> a(n);
    For(i,0,n) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll> (s+1,0));
    For(i,0,n){
        if(s >= a[i]) dp[i+1][a[i]]+=i+1;
        For(j,1,s){
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
            if(j+a[i]<=s) dp[i+1][j+a[i]]=(dp[i+1][j+a[i]]+dp[i][j])%MOD;
        }
    }
    For(i,1,n+1) ans=(ans+dp[i][s]*(n+1-i)%MOD)%MOD;
    cout<<ans<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}