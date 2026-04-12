#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const long long mod = 1e9 + 7;

int main() {
/**
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
*/
  int n, x;
  cin >> n >> x;
  pair<long long, long long> v;
  v.second = x;
  v.first = 0;
  for (int i = 1; i < n; i++) {
    cin >> x;
    v.first = (v.first + (v.second * x) % mod) % mod;
    // v.second += x;
    v.second = (v.second + x) % mod;
    // v.second %= mod; // avoid overflow
    // cout << "v.first: " << v.first << endl;
  }
  cout << v.first << endl;
}
