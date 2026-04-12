#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

string nn;
int n;
int pw9[4];
ll choose(ll n, int r) {
  if (n < r) return 0;
  if (r == 0) return 1;
  if (r == 1) return n;
  if (r == 2) return (n * (n - 1)) / 2;
  if (r == 3) return (n * (n - 1) * (n - 2)) / 6;
  return 0;
}
ll get(int i, int nz) {
  if (nz < 0) return 0;
  if (i == (int) nn.size()) {
    return nz == 0;
  }
  ll res = 0;
  for (char d = '0'; d < nn[i]; d++) {
    int rem = nz - (d != '0');
    if (rem >= 0) res += pw9[rem] * choose(n - i - 1, rem);
  }
  res += get(i + 1, nz - (nn[i] != '0'));
  return res;
}

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  cin >> nn;
  int k; cin >> k;
  n = nn.size();
  pw9[0] = 1;
  pw9[1] = 9;
  pw9[2] = 9*9;
  pw9[3] = 9*9*9;
  cout << get(0, k) << endl;

  return 0;
}
