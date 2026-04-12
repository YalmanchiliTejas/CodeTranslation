#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int x = 0, y = 0;
  for (char c : s) {
    if (c == 'A') x++;
    else y++;
  }
  if (x && y) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}