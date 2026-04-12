#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// I wanna be the wind
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using namespace std;
const ll INF = 1e17 + 9;
ll mult(ll a,ll b){
    return a*b%MOD;
}
ll fastpow(ll a, ll b){
    ll calc=1;
    for(;b>=1LL;b/=2LL){
        if((b&1LL))calc=mult(calc,a);
        a=mult(a,a);
    }
    return calc;
}
ll soma(ll a,ll b){
    if(a+b>MOD)return a+b-MOD;
    else return a+b;
}
ll subt(ll a,ll b){
    if(a-b<0)return a-b+MOD;
    else return a-b;
}
ll add_self(ll &a, ll b){
    a+=b;
    if(a>=MOD)a-=MOD;
    return a;
}
ll dp[10001][102+2][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string k;
    ll d;
    cin>>k>>d;
    ll cont = 0;
    vector<int> nums;
    rep(i,0,sz(k)){
        cont++;
        nums.push_back(k[i]-'0');
    }
    memset(dp,0,sizeof dp);
    rep(i,0,nums[0]) add_self(dp[0][i%d][1],1);
    add_self(dp[0][nums[0]%d][0],1);
    rep(i,1,cont){
        rep(soma,0,d){
            rep(j,0,10){
                if(j>nums[i]){
                    add_self(dp[i][(j+soma)%d][1],dp[i-1][soma][1]);
                }
                else if(j<nums[i]){
                    add_self(dp[i][(j+soma)%d][1],dp[i-1][soma][1]);
                    add_self(dp[i][(j+soma)%d][1],dp[i-1][soma][0]);
                }
                else{
                    add_self(dp[i][(j+soma)%d][0],dp[i-1][soma][0]);
                    add_self(dp[i][(j+soma)%d][1],dp[i-1][soma][1]);
                }
            }
        }
    }
    ll ans=0;
    add_self(ans,dp[cont-1][0][1]);
    add_self(ans,dp[cont-1][0][0]);
    cout<<subt(ans,1)<<"\n";
    return 0;  
}   