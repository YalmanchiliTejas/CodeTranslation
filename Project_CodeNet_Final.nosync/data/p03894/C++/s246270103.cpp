#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<(n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
bool vis[111111];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,q;cin>>n>>q;
  vis[1]=true;
  ll now=1;
  for(int i=0;i<q;i++){
    ll a,b;cin>>a>>b;
    vis[now-1]=true;
    vis[now+1]=true;
    if(now==a)now=b;
    else if(now==b)now=a;
    bool tmp=vis[a];
    vis[a]=vis[b];
    vis[b]=tmp;
    vis[now]=true;
  }
  vis[now-1]=true;
  vis[now+1]=true;
  ll ans=0;
  for(int i=1;i<=n;i++)ans+=vis[i];
  cout<<ans<<endl;
  return 0;
}
