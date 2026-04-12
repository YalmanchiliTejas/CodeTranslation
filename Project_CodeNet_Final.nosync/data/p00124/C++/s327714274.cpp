#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int n, flag = 0;
  while (cin >> n, n) {
    if (flag++) cout << endl;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    string name[10];
    int w[10], l[10], d[10];
    for (int i = 0; i < n; i++) {
      cin >> name[i] >> w[i] >> l[i] >> d[i];
    }
    stable_sort(ord.begin(), ord.end(), [&](int a, int b) {
      return w[a] * 3 + d[a] > w[b] * 3 + d[b];
    });
    for (int i = 0; i < n; i++) {
      cout << name[ord[i]] << "," << w[ord[i]] * 3 + d[ord[i]] << endl;
    }
  }

  return 0;
}
