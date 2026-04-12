#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define db long double
#define ii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
#define SET(A, val) memset(A, val, sizeof(A))
typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set ;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N=200005,mod=1e9+7;
const ll inf = (ll)1e15;
int add(int x,int y)
{
  x+=y;
  if(x>=mod) x-=mod;
  if(x<0) x+=mod;
  return x;
}
int mult(int x,int y)
{
  ll tmp=(ll)x*y;
  if(tmp>=mod) tmp%=mod;
  return tmp;
}
int a[N],b[N],c[N];
vi v[N];
ll d[2][N],dp[2][N];
set<pair<ll,int> > s;
void dist(int u,int idx)
{
  rep(i,0,N) d[idx][i]=inf;
  s.clear();
  d[idx][u]=0; dp[idx][u]=1;
  s.insert(mp(0,u));
  while(sz(s))
    {
      u=(*s.begin()).se;
      ll tmp=(*s.begin()).fi;
      s.erase(s.begin());
      if(tmp>d[idx][u]) continue;
      for(int ind:v[u])
	{
	  int v1=(a[ind]^b[ind]^u);
	  if(d[idx][v1]>d[idx][u]+c[ind])
	    d[idx][v1]=d[idx][u]+c[ind],dp[idx][v1]=dp[idx][u];
	  else if(d[idx][v1]==d[idx][u]+c[ind])
	    dp[idx][v1]=add(dp[idx][v1],dp[idx][u]);
	  s.insert(mp(d[idx][u]+c[ind],v1));
	}
    }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  int n,m,x,y,z,s,t;
  cin>>n>>m>>s>>t;
  rep(i,1,m+1)
    {
      cin>>a[i]>>b[i]>>c[i];
      c[i]+=c[i];
      v[a[i]].pb(i); v[b[i]].pb(i);
    }
  dist(s,0); dist(t,1);
  int ans=mult(dp[0][t],dp[1][s]);
  rep(i,1,n+1)//meet at vertices
    if(d[0][i]==d[1][i] && d[0][i]==d[0][t]/2)
      ans=add(ans,-mult(mult(dp[0][i],dp[1][i]),mult(dp[0][i],dp[1][i])));
  rep(i,1,m+1)//meet at edges
    {
      if(d[0][a[i]]<d[0][t]/2 && d[1][b[i]]<d[0][t]/2 && d[0][a[i]]+d[1][b[i]]+c[i]==d[0][t])
	ans=add(ans,-mult(mult(dp[0][a[i]],dp[1][b[i]]),mult(dp[0][a[i]],dp[1][b[i]])));
      if(d[0][b[i]]<d[0][t]/2 && d[1][a[i]]<d[0][t]/2 && d[0][b[i]]+d[1][a[i]]+c[i]==d[0][t])
	ans=add(ans,-mult(mult(dp[0][b[i]],dp[1][a[i]]),mult(dp[0][b[i]],dp[1][a[i]])));
    }
  cout<<ans<<endl;
  return 0 ;
}
