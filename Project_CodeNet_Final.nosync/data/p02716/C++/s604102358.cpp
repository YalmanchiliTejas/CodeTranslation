#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
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
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll dp[200010][4];
int main(){
    ll n;cin>>n;
    vl a(n);rep(i,n)cin>>a[i];
    ll k=1+n%2;
    rep(i,200010){
        rep(j,4){
            dp[i][j]=-LINF;
        }
    }
    dp[0][0]=0;
    rep(i,n){
        rep(j,k+1){
            chmax(dp[i+1][j+1],dp[i][j]);
            ll now=dp[i][j];
            if((i+j)%2==0) now+=a[i];
            chmax(dp[i+1][j],now);
        }
    }
    ll ans=dp[n][k];
    cout<<ans<<endl;
    return 0;
}