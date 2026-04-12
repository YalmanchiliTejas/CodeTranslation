#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll


const int N=2e5+5;
int t[4*N]={0},lazy[4*N]={0};

void push(int node)
{
  for(auto child:{2*node,2*node+1})
  {
    t[child]+=lazy[node];
    lazy[child]+=lazy[node];
  }
  lazy[node]=0;
}

void update(int node, int tl, int tr, int l, int r, int add)
{
  if(l>r)
    return;
  if(tl==l&&tr==r)
  {
    t[node]+=add;
    lazy[node]+=add;
  }
  else
  {
    push(node);
    int tm=(tl+tr)>>1;
    update(2*node,tl,tm,l,min(r,tm),add);
    update(2*node+1,tm+1,tr,max(l,tm+1),r,add);
    t[node]=min(t[2*node],t[2*node+1]);
  }
}

int query(int node, int tl, int tr, int l, int r)
{
  if(l>r)
    return 0;
  if(tl==l&&tr==r)
    return t[node];
  push(node);
  int tm=(tl+tr)>>1;
  return min(query(2*node,tl,tm,l,min(r,tm)),query(2*node+1,tm+1,tr,max(l,tm+1),r));
  
}


signed main()
{
  ll n,m,tot=0,l,r,x;
  cin>>n>>m;
  vector<pair<ll,ll>> en[n+1];
  for(int i=0;i<m;i++)
  {
    cin>>l>>r>>x;
    tot+=x;
    en[r].push_back({l,x});
  }
  ll best=tot;
  
  for(int i=1;i<=n+1;i++)
  {
    for(auto p:en[i-1])
    {
      l=p.first;
      x=p.second;
      update(1,0,N-1,0,l-1,x);
    }
    best=query(1,0,N-1,0,i-1);
    update(1,0,N-1,i,i,best);
  }
  cout<<tot-best;
  return 0;
  
}