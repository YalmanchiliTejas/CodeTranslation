#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int nax = 2e5 + 5;
vector < pair < int ,int > > intervals[nax];
const ll INF = 1e18L + 5;

struct S {
  ll small, lazy;
  inline void Merge (const S& a, const S& b) {
    small = min (a.small, b.small);
  }
  inline void add (ll x) {
    small += x, lazy += x;
  }
};

vector < S > tree;

const int TYPE_ADD = 1, TYPE_MIN = 2;

void rec (int id, int low, int high, int q_low, int q_high, int type, ll& x) {
  if (high < q_low || q_high < low)
    return;
  if (q_low <= low && high <= q_high) {
    if (type == TYPE_ADD)
      tree[id].add (x);
    else
      x = min (x, tree[id].small);
    return;
  }
  for (int b : {id << 1, (id << 1) + 1})
    tree[b].add (tree[id].lazy);
  tree[id].lazy = 0;
  int last_left = (low + high) >> 1;
  rec (id << 1, low, last_left, q_low, q_high, type, x);
  rec ((id << 1) + 1, last_left + 1, high, q_low, q_high, type, x);
  tree[id].Merge (tree[id << 1], tree[(id << 1) + 1]);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  ll sum_of_scores = 0;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    intervals[b].emplace_back (a, c);
    sum_of_scores += c;
  }
  ll answer = 0;
  int base = 1;
  while (base <= n + 1)
    base <<= 1;
  tree.resize (base << 1, {INF, 0});
  ll whatever = 0 - INF;
  rec (1, 0, base - 1, 0, 0, TYPE_ADD, whatever);
  for (int i = 1; i <= n + 1; ++i) {
    for (pair < int , int > p : intervals[i - 1]) {
      whatever = p.second;
      rec (1, 0, base - 1, 0, p.first - 1, TYPE_ADD, whatever);
    }
    ll best = INF;
    rec (1, 0, base - 1, 0, base - 1, TYPE_MIN, best);
    if (i == n + 1)
      answer = best;
    whatever = best - INF;
    rec (1, 0, base - 1, i, i, TYPE_ADD, whatever);
  }
  cout << sum_of_scores - answer;
}
