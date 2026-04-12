#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll N,MOD = 1000000007,sum=0,ans=0;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
    sum+=A[i];
    sum=sum%MOD;
  }
  
  for(int i=0;i<N-1;i++){
    sum = (sum-A[i])%MOD;
    if(sum<0) sum = sum+MOD;
    ans += sum*A[i]%MOD;
    ans = ans%MOD;
    //cout << ans << endl;
  }
  
  cout << ans << endl;
  
  return 0;
}
