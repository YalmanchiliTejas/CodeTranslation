#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;};
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;};

const Int MAX = 5050;
const Int INF = 1e9;
Int dp[MAX][MAX];
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  Int n;
  cin>>n;
  vector<Int> v(n);
  for(Int i=0;i<n;i++) cin>>v[i];

  sort(v.begin(),v.end());

  unordered_map<Int, Int> rev;
  for(Int i=0;i<n;i++) rev[v[i]]=i;
  
  for(Int i=0;i<MAX;i++)
    for(Int j=0;j<MAX;j++)
      dp[i][j]=i>j?2:-INF;

  Int ans=2;
  for(Int i=0;i<n;i++){
    for(Int j=0;j<i;j++){
      Int x=v[i]+(v[i]-v[j]);
      if(!rev.count(x)) continue;
      Int k=rev[x];
      chmax(dp[k][i],dp[i][j]+1);
      chmax(ans,dp[k][i]);
    }    
  }
  
  cout<<ans<<endl;
  return 0;
}

