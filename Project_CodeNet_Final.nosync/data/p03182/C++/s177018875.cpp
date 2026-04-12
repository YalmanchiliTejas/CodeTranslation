#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int n,m,kq,tmp;
int T[4*N],B[4*N];
#define goc 1,0,n
#define lef 2*s,l,mid
#define rig 2*s+1,mid+1,r
#define mid (l+r)/2
void trans(int s)
{
  if(!B[s]) return;
  T[2*s]+=B[s];   T[2*s+1]+=B[s];
  B[2*s]+=B[s];   B[2*s+1]+=B[s];
  B[s]=0;
}
void up(int s,int l,int r,int u,int v,int x)
{
  if(l>v||u>r) return;
  if(u<=l&&r<=v)
  {
    T[s]+=x;
    B[s]+=x;
    return;
  }
  trans(s);
  up(lef,u,v,x);
  up(rig,u,v,x);
  T[s]=max(T[2*s],T[2*s+1]);
}
int get(int s,int l,int r,int u,int v)
{
    if(l>v||u>r) return -1e18;
    if(u<=l&&r<=v) return T[s];
    trans(s);
    return max(get(lef,u,v),get(rig,u,v));
}
struct w{int l,r,x;}q[N];
vector<int> s[N],t[N];
int l,r,x;
main()
{
  ios_base::sync_with_stdio(false),cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=m;++i)
  {
    cin>>l>>r>>x;
    q[i]={l,r,x};
    s[l].push_back(i);
    t[r].push_back(i);
  }
  for(int i=1;i<=n;++i)
  {
    for(auto&j:s[i]) up(goc,0,q[j].l-1,q[j].x);
    tmp=get(goc,0,i-1);
    kq=max(kq,tmp);
   	up(goc,i,i,tmp);
   	for(auto&j:t[i]) up(goc,0,q[j].l-1,-q[j].x);
  }
  cout<<kq;
}
/**
  f[i] : max value 1->n with ans[i] = 1;
  	   = max f[j] + a[t] for t with l[t]<=i<=r[t];
         			           and !l[t]<=j<=r[t];
  n^2 can be done iterating through all posibilities;
  we speed up the algo with a seg : seg[i] as f[i]
  while iterating through a position : i,
  all query with start point at i , we update the range [0,i-1] : a[t];
  same as if we meet a end point  , we update the range [0,i-1] : -a[t];
*/
