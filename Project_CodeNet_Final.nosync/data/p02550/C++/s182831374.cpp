#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
const Int LOG = 40;
const Int MAX = 2e5;
Int dp[LOG][MAX]={};
Int sm[LOG][MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,x,m;
  cin>>n>>x>>m;

  for(Int i=0;i<m;i++){
    dp[0][i]=i*i%m;
    sm[0][i]=i;
  }

  for(Int k=0;k+1<LOG;k++){
    for(Int i=0;i<m;i++){
      dp[k+1][i]=dp[k][dp[k][i]];
      sm[k+1][i]=sm[k][i]+sm[k][dp[k][i]];
    }
  }

  Int ans=0,pos=x;
  for(Int k=0;k<LOG;k++){
    if((n>>k)&1){
      ans+=sm[k][pos];
      pos=dp[k][pos];
    }
  }
  cout<<ans<<newl;
  return 0;
}
