#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int lz[800005];
pair<int,int> seg[800005];
pair<pair<int,int>,int> pp[200004];
vector<int> x[200005],y[200005];
int dp[200005];

void build(int ver,int tl,int tr)
{
  if(tl>tr)
    return ;
  else if(tl==tr)
  {
    seg[ver].second=tl;
  }
  else
  {
    int tm=(tl+tr)/2;
    build(2*ver,tl,tm);
    build(2*ver+1,tm+1,tr);
    seg[ver]=seg[2*ver];
  }  
}

void push_lazy(int ver)
{
  lz[ver<<1]+=lz[ver];
  lz[(ver<<1)+1]+=lz[ver];
  seg[ver<<1].first+=lz[ver];
  seg[(ver<<1)+1].first+=lz[ver];
  lz[ver]=0;
}
 
void upd1(int ver,int tl,int tr,int pos,int val)
{
  if(tl>tr)
    return ;
  else if(tl==tr)
    seg[ver].first=val;
  else
  {
    int tm=(tl+tr)/2;
    if(lz[ver])
      push_lazy(ver);
    if(tm>=pos)
      upd1(ver<<1,tl,tm,pos,val);
    else
      upd1(1+(ver<<1),tm+1,tr,pos,val);
    if(seg[ver<<1].first==seg[1+(ver<<1)].first)
      seg[ver]=min(seg[ver<<1],seg[1+(ver<<1)]);
    else
      seg[ver]=max(seg[ver<<1],seg[1+(ver<<1)]);
  }
}

void upd2(int ver,int tl,int tr,int l,int r,int val)
{
  if(tl>tr||l>r||r<tl||l>tr)
    return ;
  else if(tl==l&&tr==r)
  {
    seg[ver].first+=val;
    lz[ver]+=val;
  }
  else
  {
    int tm=(tl+tr)/2;
    if(lz[ver])
      push_lazy(ver);
    upd2(ver<<1,tl,tm,l,min(tm,r),val);
    upd2(1+(ver<<1),tm+1,tr,max(tm+1,l),r,val);
    if(seg[ver<<1].first==seg[1+(ver<<1)].first)
      seg[ver]=min(seg[ver<<1],seg[1+(ver<<1)]);
    else
      seg[ver]=max(seg[ver<<1],seg[1+(ver<<1)]);

  }  
}

pair<int,int> get(int ver,int tl,int tr,int l,int r)
{
  if(tl>tr||l>r||tr<l||r<tl)
    return {-1e17,0};
  else if(tl==l&&tr==r)
    return seg[ver];
  else
  {
    int tm=(tl+tr)/2;
    if(lz[ver])
      push_lazy(ver);
    if(seg[ver<<1].first==seg[1+(ver<<1)].first)
      seg[ver]=min(seg[ver<<1],seg[1+(ver<<1)]);
    else
      seg[ver]=max(seg[ver<<1],seg[1+(ver<<1)]);

    pair<int,int>p1=get(ver<<1,tl,tm,l,min(tm,r));
    pair<int,int>p2=get(1+(ver<<1),tm+1,tr,max(tm+1,l),r);
    if(p1.first==p2.first)
      return min(p1,p2);
    return max(p1,p2);
  }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(0);   
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif

// -------------------------------------Code starts here---------------------------------------------------------------------     

  int n,m;
  cin>>n>>m;
  build(1,1,n);
  for(int i=1;i<=m;i++)
  {
    cin>>pp[i].first.first>>pp[i].first.second>>pp[i].second;
    x[pp[i].first.first].push_back(i);
    y[pp[i].first.second].push_back(i);
  }
  int cur=0,mx=0;
  int prev=0;
  for(int i=1;i<=n;i++)
  {
    for(auto j:x[i])
      cur+=pp[j].second;
    pair<int,int> z=get(1,1,n,1,i-1);
    if(z.first<0)
    {
      z.first=0;
      z.second=0;
    }
    dp[i]=z.first+cur;
    if(dp[i]>mx)
    {
      mx=dp[i];
    }
    upd1(1,1,n,i,dp[i]);
    for(auto j:x[i])
    {
      prev-=pp[j].second;
    }
    upd2(1,1,n,i,i,prev);
    for(auto j:y[i])
    {
      prev+=pp[j].second;
      upd2(1,1,n,pp[j].first.first,pp[j].first.second,pp[j].second);
      cur-=pp[j].second;
    }        
  }
  cout<<mx<<'\n';


// -------------------------------------Code ends here------------------------------------------------------------------
    clock_t clk;
  clk = clock();

    clk = clock() - clk;
  cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
  return 0;
}
