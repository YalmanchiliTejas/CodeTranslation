#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  x                     first                 
#define  y                     second                
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,d,dp[10008][108][2],dig[10008],sz;
string k;

ll rec(ll ind, ll s, ll f1){
    if(ind == sz){
        if(s == 0) return 1;
        return 0;
    }
    if(dp[ind][s][f1] != -1) return dp[ind][s][f1];
    dp[ind][s][f1] = 0;
    ll j = 9;
    if(f1 == 1) j = dig[ind];
    for(int i = 0; i <= j; i++){
        dp[ind][s][f1] += rec(ind+1,(s+i)%d,f1&(dig[ind]==i));
        dp[ind][s][f1] %= mod;
    }
    return dp[ind][s][f1];
}

ll solve(){
    memset(dp,-1,sizeof(dp));
    cin>>k>>d;
    sz = k.size();
    for(int i = 0; i < sz; i++) dig[i] = k[i] - '0';
    ll ans = rec(0,0,1)-1;
    if(ans < 0) ans += mod;
    cout<<ans<<endl;
}

int main(){
    fastio;
    //cin>>t;
    while(t--){
        solve();
    }
}