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
const int N=200005;
int x[N],y[N],p[N],a[N],b[N],w[N],ind[N];
ii x1[N],y2[N];
map<int,vi> mx,my;
int finda(int x)
{
  return ((p[x]==x)?x:p[x]=finda(p[x]));
}
int combine(int x,int y)
{
  int x1=finda(x),y1=finda(y);
  if(x1==y1) return 0;
  p[y1]=x1;
  return 1;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  int n,c1=0,c2=0;
  cin>>n;
  rep(i,1,n+1)
    {
      cin>>x[i]>>y[i],p[i]=i;
      mx[x[i]].pb(i);
      my[y[i]].pb(i);
    }
  for(auto it:mx)
    {
      vi tmp=it.se;
      x1[++c1]=mp(it.fi,tmp[0]);
      rep(i,1,sz(tmp))
	combine(tmp[i],tmp[0]);
    }
  for(auto it:my)
    {
      vi tmp=it.se;
      y2[++c2]=mp(it.fi,tmp[0]);
      rep(i,1,sz(tmp))
	combine(tmp[i],tmp[0]);
    }
  rep(i,1,c1)
    {
      a[i]=x1[i].se; b[i]=x1[i+1].se;
      w[i]=x1[i+1].fi-x1[i].fi; ind[i]=i;
    }
  rep(i,1,c2)
    {
      a[c1+i-1]=y2[i].se; b[c1+i-1]=y2[i+1].se;
      w[c1+i-1]=y2[i+1].fi-y2[i].fi; ind[c1+i-1]=c1+i-1;
    }
  sort(ind+1,ind+c1+c2-1,[](int i,int j){return w[i]<w[j];});
  ll ans=0;
  rep(i,1,c1+c2-1)
    if(combine(a[ind[i]],b[ind[i]]))
      ans+=w[ind[i]];
  cout<<ans<<endl;
  return 0 ;
}
