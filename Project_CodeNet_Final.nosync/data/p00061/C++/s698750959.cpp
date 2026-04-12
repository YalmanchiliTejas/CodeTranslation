#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n, p;
  vector<vector<int>> v(31);
  vector<int> ans(100);
  while(scanf("%d,%d", &n, &p), n+p) {
    v[p].push_back(n);
  }

  int cnt = 1;
  for(int i = 30; i >= 0; i--) {
    if(v[i].size() != 0) {
      for(int j = 0; j < v[i].size(); j++) {
        ans[v[i][j]] = cnt;
      }
      cnt++;
    }
  }

  while(cin >> n) {
    cout << ans[n] << endl;
  }
}
  