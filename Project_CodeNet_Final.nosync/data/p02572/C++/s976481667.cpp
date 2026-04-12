#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll multi_p(ll a, ll n, ll p) {
  if (n == 1) return a;
  if (n % 2) return (a * multi_p(a, n-1, p)) % p;
   
  ll t = multi_p(a, n/2, p);
  
  return (t * t) % p;
}

const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  ll sum = 0;
  
  for (int i = 0; i < N; i++) {
    sum += A[i];
    sum %= MOD;
  }
  
  ll sum1 = (sum * sum) % MOD; 
  
  ll sum2 = 0;
  for (int i = 0; i < N; i++) {
    sum2 += A[i] * A[i];
    sum2 %= MOD;
  }
  
  ll ans = (sum1 - sum2 + MOD) * multi_p(2, MOD-2, MOD);
  ans %= MOD;
  cout << ans << endl;
  
  
}