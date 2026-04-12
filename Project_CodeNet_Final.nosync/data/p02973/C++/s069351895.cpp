#include <bits/stdc++.h>
using namespace std;
using PP = pair<long, long>;
const int INF = 1e9;
template <class T> T Next() { T buf; cin >> buf; return buf; }

int n;
int a[100000];
int d[100001];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  fill(d, d + n + 1, -INF);
  
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    auto lit = upper_bound(d, d + n + 1, a[i], greater<int>());
    *lit = a[i];
    mx = max<int>(mx, lit - d + 1);
  }
  cout << mx << endl;
}