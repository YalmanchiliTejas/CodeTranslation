#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int n, m;
  cin >> n >> m;
  if (n == m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}