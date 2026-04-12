#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

    

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);
  vector<vector<ll>> dp(N, vector<ll>(3));
  dp.at(0).at(0)=0;
  dp.at(0).at(1)=0;
  dp.at(0).at(2)=A.at(0);
  dp.at(1).at(0)=0;
  dp.at(1).at(1)=max(A.at(0),A.at(1));
  if(N==2){
    cout << dp.at(1).at(1) << endl;
    return 0;
  }
  for(ll i=2;i<N;i++){
    for(ll j=0;j<=2-(i%2);j++){
      if(i==2&&j==0){
        dp.at(i).at(j)=0;
        continue;
      }
      if(i%2==0){
        if(j==0||j==1){
          dp.at(i).at(j)=max(dp.at(i-2).at(j)+A.at(i),dp.at(i-1).at(j));
        }else{
          dp.at(i).at(j)=dp.at(i-2).at(j)+A.at(i);
        }
      }else{
        dp.at(i).at(j)=max(dp.at(i-2).at(j)+A.at(i),dp.at(i-1).at(j+1));
      }
    }
  }
  cout << dp.at(N-1).at(1) << endl;
}