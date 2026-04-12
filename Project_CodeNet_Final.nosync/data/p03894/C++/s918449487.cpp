#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  v[0] = 2;
  v[1] = 1;
  int now = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    swap(v[a], v[b]);
    if (v[a] == 2) {
      now = a;
    }
    if (v[b] == 2) {
      now = b;
    }
    if (now - 1 >= 0)
      v[now - 1] = 1;
    if (now + 1 < n)
      v[now + 1] = 1;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
    if (v[i])
      ans++;
  cout << ans << endl;

  return 0;
}