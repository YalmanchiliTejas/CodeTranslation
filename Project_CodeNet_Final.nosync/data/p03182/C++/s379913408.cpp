#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n)
#define ll long long
#define _ << " " <<
#define pb push_back

using namespace std;

const int mod = 1e9 + 7;
int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
};

#define int ll

typedef pair<int, int> pii;

const int off = 1 << 18, MAXN = 2e5 + 5;

ll mx[2 * off], p[2 * off];
/*
void prop(int x) {
  if(p[x]) {
    mx[x] += x;
    if(x < off) {
      p[x * 2] += p[x];
      p[x * 2 + 1] += p[x];
    }
    p[x] = 0;
  }
}*/
void upd(int x, int lo, int hi, int a, int b, int v) {
  if(lo >= a && hi <= b) {
    p[x] += v;
    mx[x] += v;
    //prop(x);
    return;
  }
  //prop(x);
  if(lo >= b || hi <= a) {
    return;
  }

  int mi = (lo + hi) >> 1;
  upd(x * 2 + 0, lo, mi, a, b, v);
  upd(x * 2 + 1, mi, hi, a, b, v);
  mx[x] = max(mx[x * 2], mx[x * 2 + 1]) + p[x];
}
void upd2(int x, int lo, int hi, int a, int b, int v) {
  if(lo >= a && hi <= b) {
    p[x] = v;
    mx[x] = v;
    //prop(x);
    return;
  }
  //prop(x);
  if(lo >= b || hi <= a) {
    return;
  }

  int mi = (lo + hi) >> 1;
  upd(x * 2 + 0, lo, mi, a, b, v);
  upd(x * 2 + 1, mi, hi, a, b, v);
  mx[x] = max(mx[x * 2], mx[x * 2 + 1]) + p[x];
}/*
ll get(int x, int lo, int hi, int a, int b) {
  if(hi <= lo) return 0;
  prop(x);
  if(lo >= a && hi <= b) {
    return mx[x];
  }
  if(lo >= b || hi <= a) {
    return 0;
  }

  int mi = (lo + hi) >> 1;
  return max(get(x * 2 + 0, lo, mi, a, b),
             get(x * 2 + 1, mi, hi, a, b));
}*/
ll sol;

vector<pii> e[MAXN];
ll dp[MAXN];

signed main() {
  int n, m; cin >> n >> m;

  REP(i, m) {
    int l, r, a; cin >> l >> r >> a;
    e[r].pb({l, -a});
  }

  FOR(i, 1, n + 1) {
    ll tmp = mx[1], best = 0;
//    sort(e[i].begin(), e[i].end());
//    reverse(e[i].begin(), e[i].end());

    ll tmp_add = 0;

    int lst = i;

    for(auto p: e[i]) {
      int ii = p.first;
      int cost = -p.second;

      tmp += cost;

      if(ii < i) upd(1, 0, off, ii, i, cost);
    }

    if(i == n) sol = tmp;
    upd2(1, 0, off, i, i + 1, tmp);
  }

  sol = max(sol, mx[1]);

  cout << sol << endl;
}
