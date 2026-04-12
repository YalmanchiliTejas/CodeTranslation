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
typedef pair<l_l,ll> lll;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
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
ll n,m;
vl g[10];
bool vis[10];
ll ans;
void dfs(ll now,ll last,set<ll> s){
    s.insert(now);
    if(sz(s)==n)ans++;
    for(auto next:g[now]){
        if(next==last)continue;
        if(s.count(next))continue;
        dfs(next,now,s);
    }
    return;
}
int main(){
    cin>>n>>m;
    ans=0;
    rep(i,m){
        ll u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
    }
    set<ll> s;
    dfs(1,-1,s);
    cout<<ans<<endl;
    return 0;
}