#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, path = 0;
  scanf("%d %d", &n, &m);
  vector<vector<int>> v(n+1);//v[0] = []
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<int> order(n);
  for(int i = 0; i < n; i++) order[i] = i + 1;
  do {
    bool reach = true;
    for(int i = 0; i < n - 1; i++) {
      auto result = find(v[order[i]].begin(), v[order[i]].end(), order[i + 1]);
      if(result == v[order[i]].end()) {
        reach = false;
        break;
      }
    }
    if(reach) path++;
  } while (next_permutation(order.begin()+1, order.end()));
  cout << path;
}