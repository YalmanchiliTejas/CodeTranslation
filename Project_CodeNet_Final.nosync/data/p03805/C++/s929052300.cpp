#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

int main() {
  int n, m, a, b, i, j, cnt = 0;
  cin >> n >> m;
  vector<int> line(n);
  for (i = 0; i < n; ++i) line[i] = i + 1;
  vector<vector<int>> table(n, vector<int>(n, 0));
  for (i = 0; i < m; ++i) {
    cin >> a >> b;
    table[a - 1][b - 1] = 1;
    table[b - 1][a - 1] = 1;
  }

  do {
    if (line[0] != 1) break;
    for (i = 0; i < n - 1; ++i) {
      if (table[line[i] - 1][line[i + 1] - 1] == 0) break;
      if (table[line[i] - 1][line[i + 1] - 1] == 1) continue;
      if (table[line[i + 1] - 1][line[i] - 1] == 1) continue;
    }
    if (i == n - 1) cnt++;
  } while (next_permutation(line.begin(), line.end()));

  cout << cnt << endl;
  return 0;
}
