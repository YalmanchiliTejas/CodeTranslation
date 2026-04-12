#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
  ll N,i,ans=0,S=0,MOD=1e9+7;
  cin>>N;
  vector<ll> A(N);
  for (i=0;i<N;i++) {
    cin>>A[i];
    S+=A[i];
  }
  for (i=0;i<N;i++) {
    S-=A[i];
    ans += A[i]*(S%MOD)%MOD;
    ans %= MOD;
  }
  cout<<ans<<endl;
  return 0;
}
