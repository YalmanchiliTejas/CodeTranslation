#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cld;
class disjoint_set {
  public:
    int cnt;
    vector<int> rank, prt, now, lg;
    disjoint_set(int size) {
      cnt = size;
      rank.resize(size);
      prt.resize(size);
      now.resize(size);
      lg.resize(2 * size - 1);
      lg.resize(2 * size - 1);
      for (int i = 0; i < size; i++) {
        prt[i] = i;
        rank[i] = 0;
        now[i] = i;
      }
    }
  int find (int x) {
    if (x == prt[x]) return x;
    return prt[x] = find(prt[x]);
  }
  bool is_equiv (int x, int y) {
    return find(x) == find(y);
  }
  int unite (int x, int y) {
    x = find(x);
    y = find(y);
    lg[now[x]] = lg[now[y]] = cnt;
    cld[cnt].push_back(now[x]);
    cld[cnt].push_back(now[y]);
    now[x] = now[y] = cnt;
    if (x == y) return false;
    if (rank[x] > rank[y]) swap(x, y);
    prt[x] = y;
    if (rank[x] == rank[y]) rank[y]++;
    return cnt++;
  }
};
vector<int> dpt;
void dfs (int crr, int d) {
  dpt[crr] = d;
  for (int nxt : cld[crr]) {
    dfs(nxt, d + 1);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> grh(m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    grh[i] = {c, {--a, --b}};
  }
  sort(grh.begin(), grh.end());
  int N = 2 * n - 1;
  cld.resize(N);
  vector<int> cut(N);
  disjoint_set djs(n);
  long long sum = 0;
  int cnt = 0;
  for (auto e : grh) {
    int c = e.first;
    int a = e.second.first;
    int b = e.second.second;
    if (!djs.is_equiv(a, b)) {
      cut[djs.unite(a, b)] = c;
      sum += c;
      cnt++;
    }
  }
  const int PMAX = 20;
  vector<vector<int>> asc(PMAX, vector<int>(N));
  for (int i = 0; i < N; i++) {
    asc[0][i] = djs.lg[i];
  }
  asc[0][N - 1] = N - 1;
  for (int p = 1; p < PMAX; p++) {
    for (int i = 0; i < N; i++) {
      asc[p][i] = asc[p - 1][asc[p - 1][i]];
    }
  }
  dpt.resize(N);
  dfs(N - 1, 0);
  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    if (dpt[--s] > dpt[--t]) swap(s, t);
    int d = dpt[t] - dpt[s];
    for (int p = 0; p < PMAX; p++){
      if (d & 1) {
        t = asc[p][t];
      }
      d >>= 1;
      if (d == 0) break;
    }
    long long ret = sum;
    for (int p = PMAX - 1; p >= 0; p--) {
      if (asc[p][s] != asc[p][t]) {
        s = asc[p][s];
        t = asc[p][t];
      }
    }
    if (s != t) {
      s = asc[0][s];
      t = asc[0][t];
    }
    ret -= cut[s];
    cout << ret << '\n';
  }
  return 0;
}