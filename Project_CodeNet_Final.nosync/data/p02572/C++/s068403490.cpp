#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 +7;

int Pow(int p) {
  //cout << p << endl;
  if(p == 0) return 1 % mod;
  int temp = Pow(p / 2) % mod;
  temp = ((temp % mod) * (temp % mod)) % mod;;
  //int temp = ((Pow(p / 2) % mod) * (Pow(p / 2) % mod)) % mod;
  if(p & 1) temp = ((temp % mod) * (2 % mod)) % mod;
  return temp % mod;
}

int32_t main() {
  int n; cin >> n;
  int sum1 = 0, sum2 = 0;
  for(int i = 0; i < n; ++i) {
    int a; cin >> a;
    sum1 = ((sum1 % mod) + (a % mod)) % mod;
    sum2 = ((sum2 % mod) + ((a % mod) * (a % mod)) % mod) % mod;
  }
  sum1 = ((sum1 % mod) * (sum1 % mod)) % mod;
  int ans = (((sum1 - sum2) % mod) * Pow(mod - 2) % mod) % mod;
  ans = (ans + mod) % mod;
  cout << ans;
  return 0;
}