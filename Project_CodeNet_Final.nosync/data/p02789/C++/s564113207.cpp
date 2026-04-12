#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define DD long double

#define M 1000000007
#define INF 1e18

void setIO(string s = "") { 
  cin.sync_with_stdio(0); cin.tie(0);
  if (s.size()) s += ".in", freopen(s.c_str(), "r", stdin);
}

int tt = 1;
void solve() {
  int n, m;
  cin >> n >> m;
  cout << ((n == m) ? "Yes" : "No") << endl;
}

int main() {
  setIO();
  while (tt--) {
    solve();
  }
  return 0;
}