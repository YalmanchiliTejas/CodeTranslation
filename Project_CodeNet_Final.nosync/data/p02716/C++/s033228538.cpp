#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
const ll MOD=1000000007,MOD2=998244353,INF=1e18;



int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a.at(i);
    vector<vector<ll>> dp(n,vector<ll>(5,-INF));
    dp.at(0).at(0)=a.at(0);
    dp.at(1).at(1)=a.at(1);
    if(n>2)dp.at(2).at(2)=a.at(2);
    int yutori;
    if(n%2==0){yutori=1;}
    else{yutori=2;}
    rep(i,n){
        rep(j,3){
            if(i+2<=n-1)chmax(dp.at(i+2).at(j),dp.at(i).at(j)+a.at(i+2));
            if(i+3<=n-1)chmax(dp.at(i+3).at(j+1),dp.at(i).at(j)+a.at(i+3));
            if(i+4<=n-1)chmax(dp.at(i+4).at(j+2),dp.at(i).at(j)+a.at(i+4));
        }
    }
    ll ans=dp.at(n-1).at(yutori);
    chmax(ans,dp.at(n-2).at(yutori-1));
    if(yutori==2)chmax(ans,dp.at(n-3).at(yutori-2));
    cout<<ans<<endl;
}
