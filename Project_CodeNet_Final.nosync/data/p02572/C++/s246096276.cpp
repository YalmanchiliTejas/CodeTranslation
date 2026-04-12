#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  long long all = 0, ans = 0;
  cin >> n;

  vector<int>a(n);

  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    all += a.at(i);
  }
  long long store;
  for (int i = 0; i < n-1; i++) {
    all -= a.at(i);
    store = all % (1000000007);
    ans += a.at(i) * store;
    ans = ans % (1000000007);
  }
  cout << ans << endl;
}