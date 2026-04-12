#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7;

int main() {
  ll N; cin>>N;
  vector<ll> A(N);
  ll sum = 0;
  ll ans = 0;
  for(int i=0; i<N; ++i) {
    cin>>A[i];
    sum=(sum+A[i])%MOD;
  }
  for(int i=0; i<N; ++i) {
    sum=(sum-A[i]+MOD)%MOD;
    ans=(ans+A[i]*sum)%MOD;
  }
  cout << ans << endl;
}
