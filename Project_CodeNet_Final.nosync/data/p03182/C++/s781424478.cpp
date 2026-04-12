#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MXN=200005;
const int OFF=1<<18;

int n,m;
ll t[2*OFF];
ll p[2*OFF];
vector<array<int,2>>add[MXN];
vector<array<int,2>>del[MXN];

void propagate(int x){
  t[2*x+1]+=p[x];
  p[2*x+1]+=p[x];
  t[2*x+2]+=p[x];
  p[2*x+2]+=p[x];
  p[x]=0;
}

void upd(int l,int r,ll v,int lo=0,int hi=OFF,int x=0){
  if(r<=lo||hi<=l)return;
  if(l<=lo&&hi<=r){
    t[x]+=v;
    p[x]+=v;
    return;
  }
  propagate(x);
  int md=(lo+hi)/2;
  upd(l,r,v,lo,md,2*x+1);
  upd(l,r,v,md,hi,2*x+2);
  t[x]=max(t[2*x+1],t[2*x+2]);
}

ll get(int l,int r,int lo=0,int hi=OFF,int x=0){
  if(r<=lo||hi<=l)return -1e18;
  if(l<=lo&&hi<=r)return t[x];
  propagate(x);
  int md=(lo+hi)/2;
  return max(get(l,r,lo,md,2*x+1),get(l,r,md,hi,2*x+2));
}

int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;++i){
    int l,r,a;
    scanf("%d%d%d",&l,&r,&a);
    add[l].push_back({r,a});
    del[r].push_back({l,a});
  }
  ll curr=0;
  for(int i=1;i<=n;++i){
    for(auto&a:add[i])upd(i,a[0]+1,-a[1]),curr+=a[1];
    upd(i,i+1,get(0,i)+curr);
    for(auto&a:del[i])upd(a[0],i+1,+a[1]),curr-=a[1];
  }
  printf("%lld\n",get(0,n+1));
}
