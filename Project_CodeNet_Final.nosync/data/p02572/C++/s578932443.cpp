#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
using ll = long long;
 
int main() {
 
  int N;
  cin >> N;
  
  vector<ll> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  ll ans = 0;
  ll temp;
  for(int i = 1; i < N; i++){
    temp += A.at(i-1);
    temp %= MOD;
    ans += A.at(i) * temp % MOD;
  }
  ans %= MOD;
  cout << ans << endl;
}