#include <bits/stdc++.h>

using namespace std;
using ll = long long;

tuple<int,int,int> a[200005];

ll dp[200005];
int trstp = 1;
ll add[1 << 20];
ll lo[1 << 20];
void split(int i) {
  lo[2*i] += add[i];
  add[2*i] += add[i];
  lo[2*i + 1] += add[i];
  add[2*i + 1] += add[i];
  add[i] = 0;
}
ll query(int root, int u, int v, int s = 1, int e = trstp) {
  if (v < s || e < u) return 1e18;
  if (u <= s && e <= v) return lo[root];
  split(root);
  int mid = (s + e)/2;
  return min(query(2*root, u, v, s, mid), query(2*root + 1, u, v, mid + 1, e));
}
void update(int root, int u, int v, ll x, int s = 1, int e = trstp) {
  if (v < s || e < u) return;
  if (u <= s && e <= v) {
    add[root] += x;
    lo[root] += x;
    return;
  }
  int mid = (s + e)/2;
  split(root);
  update(2*root, u, v, x, s, mid);
  update(2*root + 1, u, v, x, mid + 1, e);
  lo[root] = min(lo[2*root], lo[2*root + 1]);
}

int main() {
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  for (int i = 0; i < m; i++) {
    int val, l, r;
    cin >> l >> r >> val;
    sum += val;
    a[i] = make_tuple(l, r, val);
  }
  sort(a, a + m);

  while (trstp < n + 1) trstp *= 2;
  int j = m - 1;
  for (int i = n; i >= 1; i--) {
    dp[i] = query(1, i + 1, n + 1);
    update(1, i, i, dp[i]);
    while (j >= 0 && get<0>(a[j]) == i) {
      update(1, get<1>(a[j]) + 1, n + 1, get<2>(a[j]));
      j--;
    }
  }
  cout << sum - query(1, 1, n + 1) << '\n';

  return 0;
}
