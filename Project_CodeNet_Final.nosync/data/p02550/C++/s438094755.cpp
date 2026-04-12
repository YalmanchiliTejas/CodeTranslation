#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define debug(output) cout<<#output<<"= "<<output<<endl

using P=pair<int,int>;
using lint=long long;
using ll=long long;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  lint n,x,m;cin>>n>>x>>m;
  vector<lint> a(m+5,0);
  a[1]=x;
  lint c=0;
  map<lint,int> memo;
  memo[a[1]]=0;
  lint key=0;
  bool first=true;
  for(int i=2;i<=m+1;++i){
    a[i]=a[i-1]*a[i-1]%m;
    if(memo.find(a[i])==memo.end()&&first){
      memo[a[i]]=i;//first=false;
    }
    else{
      c=i-memo[a[i]];
      key=memo[a[i]];
      memo[a[i]]=i;
    }
  }
  if(n<=m){
    lint res=0;
    rep1(i,n)res+=a[i];
    cout<<res<<"\n";
    return 0;
  }
  lint sm=0;
  for(int i=key;i<key+c;++i){
    sm+=a[i];
  }
  lint res=0;
  for(int i=1;i<key;++i)res+=a[i];
  res+=sm*((n-key+1)/c);
  for(int i=key;i<key+(n-key+1)%c;++i)res+=a[i];
  cout<<res<<"\n";
  //debug(sm);
  return 0;
}