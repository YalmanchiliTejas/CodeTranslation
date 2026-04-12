#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 300000
#define INF 10000000000000000
using Graph=vector<vector<int>>;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  vector<ll> sum_o(N,0),sum_e(N,0);
  sum_o.at(0)=A.at(0);
  for(int i=2;i<N;i+=2){
    sum_o.at(i)=sum_o.at(i-2)+A.at(i);
  }
  sum_e.at(1)=A.at(1);
  for(int i=3;i<N;i+=2){
    sum_e.at(i)=sum_e.at(i-2)+A.at(i);
  }
  if(N%2==0){
    ll ans=sum_e.at(N-1);
    for(int i=0;i<N;i+=2){
      ans=max<ll>(ans,sum_o.at(i)+sum_e.at(N-1)-sum_e.at(i+1));
    }
    cout<<ans<<endl;
  }else{
    vector<vector<ll>> dp(N,vector<ll>(3,-INF));
    dp.at(0).at(2)=A.at(0);
    dp.at(1).at(1)=A.at(1);
    dp.at(2).at(0)=A.at(2);
    for(int i=0;i<N;i++){
      if(i+2<N){
        for(int j=0;j<3;j++){
          dp.at(i+2).at(j)=max<ll>(dp.at(i).at(j)+A.at(i+2),dp.at(i+2).at(j));
        }
      }
      if(i+3<N){
        for(int j=1;j<3;j++){
          dp.at(i+3).at(j-1)=max<ll>(dp.at(i).at(j)+A.at(i+3),dp.at(i+3).at(j-1));
        }
      }
      if(i+4<N){
        dp.at(i+4).at(0)=max<ll>(dp.at(i).at(2)+A.at(i+4),dp.at(i+4).at(0));
      }
    }
    ll ans=dp.at(N-1).at(0);
    ans=max<ll>(ans,dp.at(N-2).at(1));
    ans=max<ll>(ans,dp.at(N-3).at(2));
    cout<<ans<<endl;
  }
}
