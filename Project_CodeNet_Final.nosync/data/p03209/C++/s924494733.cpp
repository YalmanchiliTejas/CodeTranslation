#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N,X;
  cin>>N>>X;
  vector<ull>dp(N+1);
  dp[0]=1;
  for(int i=0;i<N;i++)dp[i+1]=1+dp[i]+1+dp[i]+1;
  vector<ull>p(N+1);
  p[0]=1;
  for(int i=0;i<N;i++)p[i+1]=p[i]+1+p[i];
  ull ans=0;
  for(int i=N;i>=0;i--){
    if(i==0){
      ans++;
      break;
    }
    if(X<=1){
      break;
    }
    else if(X<=dp[i-1]+1){
      X--;
    }
    else if(X==dp[i-1]+2){
      ans+=p[i-1]+1;
      break;
    }
    else if(X<=dp[i-1]+dp[i-1]+2){
      ans+=p[i-1]+1;
      X-=dp[i-1]+2;
    }
    else{
      ans+=p[i];
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}
