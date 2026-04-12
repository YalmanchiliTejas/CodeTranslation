#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9 + 7;

int r, g, b;

void solve()
{
  cin >> r >> g >> b;
  if((g * 10 + b) % 4) {
    cout << "NO\n";
  }else {
    cout << "YES\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}