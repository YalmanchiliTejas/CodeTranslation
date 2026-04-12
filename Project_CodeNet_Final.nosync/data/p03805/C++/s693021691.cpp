#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  int t[10][10] = {0};
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b; a--; b--;
    t[a][b] = t[b][a] = 1;
  }

	vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }

  int ans = 0;
  do {
    int flag = 1;
		if (p[0]) break;
    for (int i = 1; i < n; i++) {
      if (t[p[i]][p[i-1]] == 0) {
        flag = 0;
      }
    }
    if (flag) {
      ans++;
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << endl;

  return 0;
}