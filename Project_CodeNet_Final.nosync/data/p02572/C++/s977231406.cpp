#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

  ll N;
  cin >> N;

  vector<ll> A(N);
  ll sum = 0;
  const ll mod = 1000000007;

  for(ll i = 0; i < N; i++){
    cin >> A[i];
    sum += A[i];
    sum = sum % (2 * mod);
  }

  ll ans = 0;
  for(ll i = 0; i < N; i++){
    if(sum > A[i]){
      ans += A[i] * (sum - A[i]);
    }else{
      ans += A[i] * (sum + 2 * mod - A[i]);
    }
    ans = ans % (2 * mod);
  }

  ans = ans / 2;
  ans = ans % mod;

  cout << ans << endl;
}