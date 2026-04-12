#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)

int path(int now, map<int, bool> pre, vector<vector<int>> gr) {
  pre[now] = true;
  int count = 0;
  bool update = false;
  REP(i, gr[now].size()) {
    if(pre[gr[now][i]] == false) {
      count += path(gr[now][i], pre, gr);
      update = true;
    }
  }

  if(!update) {
    FOR(i, 1, gr.size()) {
      if(pre[i] == false) return 0;
    }
    return 1;
  }

  return count;
}

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  int n, m; cin >> n >> m;
  vector<vector<int>> gr(n+1);
  int a, b;
  REP(i, m) {
    cin >> a >> b;
    gr[a].pb(b);
    gr[b].pb(a);
  }

  map<int, bool> pre;
  int now = 1;
  int count = path(now, pre, gr);

  cout << count << endl;

}
