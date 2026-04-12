#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  ll sum(0);
  for(int i(0);i<N;i++){
    cin>>A[i];
    if(i != 0) {
      sum += A[i];
      sum %= MOD;
    }
  }
  ll ans(0);
  for(int i(0);i<N-1;i++){
    ans += A[i]*sum;
    ans %= MOD;
    sum -= A[i+1];
    if(sum < 0) sum += MOD;
  }
  cout << ans << endl;
  return 0;
}
