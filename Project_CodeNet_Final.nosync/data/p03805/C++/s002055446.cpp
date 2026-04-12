#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int x[10][10] = {0};
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    x[a][b] = 1;
    x[b][a] = 1;
  }
  vector<int> v;
  for (int i = 2; i <= n; i++) {
    v.push_back(i);
  }
  int ans = 0;
  do {
    bool flag = true;
    if (x[1][v[0]] != 1) {
      flag = false;
    }
    for (int i = 1; i < n - 1; i++) {
      if (x[v[i - 1]][v[i]] != 1) {
        flag = false;
      }
    }
    if (flag) {
      ans++;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
}