#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// leave to tomorrow anything that can be done today
#define MOD 1e9+7
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
ll dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll vet[n+2];
    rep(i,1,n+1)cin>>vet[i];
    dp[0]=0;
    ll pr[n+2];
    pr[1]=vet[1];
    for(int i=3;i<=n;i+=2)pr[i]=vet[i]+pr[i-2];
    dp[1]=0LL;
    rep(i,2,n+1){
        if(i&1){
            dp[i] = max(vet[i]+dp[i-2],dp[i-1]);
        }
        else{
            dp[i] = max(vet[i]+dp[i-2],pr[i-1]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;   
}   