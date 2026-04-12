#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

class U {
public:
  int n;
  vector<int> p, s;

  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }

  bool connect(int a, int b) {
    int ap, bp;
    for (ap = p[a]; ap != p[ap]; ap = p[ap]);
    for (bp = p[b]; bp != p[bp]; bp = p[bp]);
    if (ap == bp)
      return true;
    int mi = min(ap, bp), ma = max(ap, bp);
    p[ma] = mi;
    s[mi] += s[ma];
    s[ma] = 0;
    for (int pp = a; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    for (int pp = b; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    return false;
  }

  int q(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return s[ap];
  }

  int parent(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return p[ap];
  }

  bool query(int a, int b) { return parent(a) == parent(b); }
};

vector<vector<pair<int, ll>>> ps;

void dfs(vector<vector<ll>> &dist, int i, int from, int base, ll maxp) {
  dist[base][i] = maxp;
  for (auto &v : ps[i]) {
    if (v.first == from) continue;
    dfs(dist, v.first, i, base, max(v.second, maxp));
  }
}

struct N {
  int a, b;
  ll c;
};

bool operator<(const N &l, const N &r) {
  return l.c < r.c;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  ps.resize(n);
  U u(n);
  ll sum = 0;
  vector<N> ns(m);
  for (int i = 0; i < m; i++) {
    cin >> ns[i].a >> ns[i].b >> ns[i].c;
    ns[i].a--;
    ns[i].b--;
  }
  sort(ns.begin(), ns.end());
  for (int i = 0; i < m; i++) {
    if (!u.connect(ns[i].a, ns[i].b)) {
      ps[ns[i].a].emplace_back(ns[i].b, ns[i].c);
      ps[ns[i].b].emplace_back(ns[i].a, ns[i].c);
      sum += ns[i].c;
    }
  }
  vector<vector<ll>> dist(n, vector<ll>(n, -1));

  for (int i = 0; i < n; i++) {
    dfs(dist, i, -1, i, 0);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    cout << sum - dist[s][t] << endl;
  }

  return 0;
}
