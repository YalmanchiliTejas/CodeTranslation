#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> Graph(n, vector<int>(0));
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  vector<int> per(0);
  int res = 0;
  rep(i,n) per.push_back(i);
  do {
    if(per[0] != 0) continue;
    bool flag = true;
    rep(i,n-1) {
      int cnt = count(Graph[per[i]].begin(), Graph[per[i]].end(), per[i+1]);
      if(cnt == 0) flag = false;
    }
    if(flag) res++;
  } while(next_permutation(per.begin(), per.end()));

  cout << res << endl;
  return 0;
}