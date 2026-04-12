#include <bits/stdc++.h>

#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;

int x;
void input() { cin >> x; }
void solve() { cout << (x >= 30 ? "Yes" : "No") << endl; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}