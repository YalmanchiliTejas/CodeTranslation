#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
  ll N;
  cin >> N;
  vector<ll> A(N,0);
  for(ll i=0;i<N;i++){
      cin>>A[i]
  ;}
  //dp[i]は長さi+1であるような広義単調増加部分列の最後の最小値
  vector<ll> dp(N,INF);
  for(ll i=N-1;i>=0;i--){
      *upper_bound(dp.begin(), dp.end(), A[i])=A[i]
  ;}
  cout<<lower_bound(dp.begin(), dp.end(), INF)-dp.begin()<<endl;
    return 0;
}
