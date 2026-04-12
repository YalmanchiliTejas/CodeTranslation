#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007
int main(){
  string N;
  int K;
  cin>>N>>K;
  int n=N.size();

  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2,vector<ll>(K+1,0)));

  ll x=N.at(0)-'0';
  dp.at(0).at(0).at(1)=1;
  dp.at(0).at(1).at(1)=x-1;
  dp.at(0).at(1).at(0)=1;
  for(int i=1;i<n;i++){
    x=N.at(i)-'0';
    for(int j=1;j<=K;j++){
      dp.at(i).at(1).at(j)+=9*dp.at(i-1).at(1).at(j-1)+dp.at(i-1).at(1).at(j);
    }
    dp.at(i).at(1).at(0)+=dp.at(i-1).at(1).at(0);
    if(x!=0){
      for(int j=1;j<=K;j++){
        dp.at(i).at(1).at(j)+=(x-1)*dp.at(i-1).at(0).at(j-1);
        dp.at(i).at(0).at(j)+=dp.at(i-1).at(0).at(j-1);
      }
      for(int j=0;j<=K;j++){
        dp.at(i).at(1).at(j)+=dp.at(i-1).at(0).at(j);
      }
    }else{
      for(int j=0;j<=K;j++){
        dp.at(i).at(0).at(j)+=dp.at(i-1).at(0).at(j);
      }
    }
  }
  cout<<dp.at(n-1).at(1).at(K)+dp.at(n-1).at(0).at(K)<<endl;
}
