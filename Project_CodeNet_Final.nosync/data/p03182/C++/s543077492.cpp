/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <LL,LL>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,n2=1,m,lb[200010],ub[200010],a[200010],dat[800010],add[800010],dp[200010],ans=0;
vector <LL> v[2][200010];

void upd(LL k,LL lb,LL ub,LL tlb,LL tub,LL val)
{
  if(ub<tlb||tub<lb) return;
  if(tlb<=lb&&ub<=tub)
  {
    add[k]+=val;
    return;
  }
  upd(k*2+1,lb,(lb+ub)/2,tlb,tub,val);
  upd(k*2+2,(lb+ub)/2+1,ub,tlb,tub,val);
  dat[k]=max(dat[k*2+1]+add[k*2+1],dat[k*2+2]+add[k*2+2]);
}

void upd2(LL k,LL val)
{
  dat[k]=val;
  while(k>0)
  {
    k=(k-1)/2;
    dat[k]=max(dat[k*2+1]+add[k*2+1],dat[k*2+2]+add[k*2+2]);
  }
}

LL query(LL k,LL lb,LL ub,LL tlb,LL tub)
{
  if(ub<tlb||tub<lb) return -1e18;
  if(tlb<=lb&&ub<=tub) return dat[k]+add[k];
  return max(query(k*2+1,lb,(lb+ub)/2,tlb,tub),query(k*2+2,(lb+ub)/2+1,ub,tlb,tub))+add[k];
}

int main()
{
  cin>>n>>m;
  while(n2<n) n2*=2;
  rep(i,m)
  {
    scanf("%lld%lld%lld",&lb[i],&ub[i],&a[i]);
    v[0][lb[i]].pb(i);
    v[1][ub[i]].pb(i);
  }
  repn(i,n2-1) upd2(i+n2-1,-1e18);
  repn(i,n)
  {
    rep(j,v[0][i].size()) upd(0,0,n2-1,0,i-1,a[v[0][i][j]]);
    dp[i]=query(0,0,n2-1,0,i-1);
    ans=max(ans,dp[i]);
    upd2(i+n2-1,dp[i]);
    rep(j,v[1][i].size()) upd(0,0,n2-1,0,lb[v[1][i][j]]-1,-a[v[1][i][j]]);
  }
  cout<<ans<<endl;
  return 0;
}