#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
#define MAX 2100000
#define INF 1001000000
using Graph=vector<vector<int>>;

int main(){
  int N,S;
  cin>>N>>S;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }

  vector<vector<ll>> dp(N+1,vector<ll>(S,0));
  dp.at(0).at(0)=1;
  for(ll i=1;i<=N;i++){
    for(int j=0;j<S;j++){
      dp.at(i).at(j)=dp.at(i-1).at(j);
    }
    if(A.at(i-1)<S){
      dp.at(i).at(A.at(i-1))+=i;
      dp.at(i).at(A.at(i-1))%=MOD;
    }
    for(int j=1;j+A.at(i-1)<S;j++){
      dp.at(i).at(j+A.at(i-1))+=dp.at(i-1).at(j);
      dp.at(i).at(j+A.at(i-1))%=MOD;
    }
  }

  ll ans=0;
  for(ll i=0;i<N;i++){
    if(S-A.at(i)==0){
      ans+=(i+1)*(N-i);
    }else if(S-A.at(i)>0){
      ans+=dp.at(i).at(S-A.at(i))*(N-i);
    }
    ans%=MOD;
  }

  cout<<ans<<endl;
}
