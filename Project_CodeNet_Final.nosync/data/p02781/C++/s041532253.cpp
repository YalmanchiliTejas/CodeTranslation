#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string N;
int n, k;
ll f[105][2][10];

ll dq(int id, int tight, int cnt) {
  if (id == 0)
    return (cnt == k);
  if (cnt > k)
    return 0;
  if (f[id][tight][cnt] != -1)
    return f[id][tight][cnt];

  ll res = 0;
  int k = tight ? (N[n - id] - '0') : 9;
  for (int i = 0; i <= k; ++i) {
    res += dq(id - 1, tight && (i == k), cnt + (i != 0));
  }

  return (f[id][tight][cnt] = res);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> N >> k;
  n = N.length();
  memset(f, -1, sizeof(f));
  cout << dq(n, 1, 0);
  return 0;
}