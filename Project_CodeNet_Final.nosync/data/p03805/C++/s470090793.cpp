#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ab(n, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    ab[a][b] = ab[b][a] = 1;
  }

  vector<int> p(n - 1);
  for (int i = 0; i < n - 1; ++i) p[i] = i + 1;

  int cnt = 0;

  do {
    // for (int t = 0; t < n - 1; ++t) cout << p[t] << " ";
    // cout << endl;
    bool rst = true;
    if (ab[0][p[0]] == 0) continue;
    for (int j = 0; j < n - 2; ++j) {
      if (ab[p[j]][p[j + 1]] == 0) rst = false;
    }
    if (rst) ++cnt;

  } while (next_permutation(p.begin(), p.end()));

  cout << cnt << endl;
}
