#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[9]={1,0,-1,0,1,1,-1,-1,0};
const ll dx[9]={0,-1,0,1,1,-1,1,-1,0};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}



int main(){
    string k;cin >> k;ll d;cin >> d;
    ll dp[k.size()+1][d][2];
    rep(i,k.size()+1)rep(j,d)rep(x,2)dp[i][j][x]=0;
    dp[0][0][0]=1;
    rep(i,k.size()){
        ll p=k[i]-'0';
        rep(j,d){
            dp[i+1][(j+p)%d][0]+=dp[i][j][0];
            dp[i+1][(j+p)%d][0]%=MOD;
            rep(x,p){
                dp[i+1][(j+x)%d][1]+=dp[i][j][0];
                dp[i+1][(j+x)%d][1]%=MOD;
            }
            rep(x,10){
                dp[i+1][(j+x)%d][1]+=dp[i][j][1];
                dp[i+1][(j+x)%d][1]%=MOD;
            }
        }
    }
    cout << (dp[k.size()][0][0]+dp[k.size()][0][1]+MOD-1)%MOD <<endl;
}