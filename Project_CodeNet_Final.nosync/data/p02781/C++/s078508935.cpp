#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

long long nCr(long long n, long long r) {
  if (n < r) return 0;
  long long ret = 1;
  for (int i = n-r+1; i <= n; ++i)
    ret *= i;
  for (int i = 2; i <= r; ++i)
    ret /= i;
  return ret;
}

void solve() {
  string n; cin >> n;
  vector<int> nz;
  for (int i = 0; i < (int)n.size(); ++i) {
    if (n[i] == '0') continue;
    nz.push_back(i);
  }
  int k; cin >> k;
  if (k > n.size()) {
    puts("0");
    return;
  }
  long long ans = nCr(n.size()-1, k)*pow(9, k);
  for (int i = 1; i <= k && i <= n.size(); ++i) {
    if (i > nz.size()) break;
    int ind = nz[i-1];
    long long cur = n[ind]-'0'-1;
    cur *= nCr(n.size()-ind-1, k-i)*pow(9, k-i);
    debug(cur);
    debug(n.size()-ind-1);
    ans += cur;
    if (k-i == 0) {
      ++ans;
      continue;
    }
    if (i+1 > nz.size()) continue;
    ans += nCr(n.size()-nz[i]-1, k-i)*pow(9, k-i);
  }
  cout << ans;
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
