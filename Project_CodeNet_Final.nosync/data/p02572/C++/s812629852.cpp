#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &i : v)
    cin >> i;
  ll int partSum = 0;
  for(int i = 0; i < n; i++) {
      partSum += v[i] % mod;
      partSum %= mod;
  }
  ll int totSum = 0;
  for(int i = 0; i < n - 1; i++) {
      partSum -= v[i] % mod;
      partSum = (partSum + mod) % mod;
      totSum += ((v[i] % mod) * (partSum % mod)) % mod;
      totSum %= mod;
  }
  cout << totSum << '\n';
}
  