#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MOD (1000000007l)
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)

using namespace std;

void solve() {
  string S;
  cin >> S;
  ll a = 0;
  ll b = 0;
  for (char c: S) if (c == 'A') a++; else b++;
  if (a > 0 and b > 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  cout << fixed;
  solve();
  return 0;
}
