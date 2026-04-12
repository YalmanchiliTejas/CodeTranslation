#include <bits/stdc++.h>
#define dum(x) cout<<#x<<'='<<x<<endl
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());

  if (n % 2 == 0) {
    ll res = 0;
    for (int i = 0; i < n / 2 - 1; ++i) {
      res -= v.at(i) * 2;
    }
    res -= v.at(n / 2 - 1);
    res += v.at(n / 2);
    for (int i = n / 2 + 1; i < n; ++i) {
      res += v.at(i) * 2;
    }
    cout << res << endl;
  } else {
    ll res_1 = 0;
    for (int i = 0; i < n / 2; ++i) {
      res_1 -= v.at(i) * 2;
    }
    res_1 += v.at(n / 2);
    res_1 += v.at(n / 2 + 1);
    for (int i = n / 2 + 2; i < n; ++i) {
      res_1 += v.at(i) * 2;
    }

    ll res_2 = 0;
    for (int i = 0; i < n / 2 - 1; ++i) {
      res_2 -= v.at(i) * 2;
    }
    res_2 -= v.at(n / 2 - 1);
    res_2 -= v.at(n / 2);
    for (int i = n / 2 + 1; i < n; ++i) {
      res_2 += v.at(i) * 2;
    }

    cout << max(res_1, res_2) << endl;
  }
}
