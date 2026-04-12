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

long long dp[4][123][2];
string n;
int k;

long long rek(int cnt, int pos, bool f) {
  if (cnt > k) return 0;
  if (pos == n.size()) return cnt == k;
  long long &ret = dp[cnt][pos][f];
  if (ret != -1) return ret;
  ret = 0;
  int lmt = f?9:(n[pos]-'0');
  for (int i = 0; i <= lmt; ++i) {
    int ncnt = cnt;
    if (i) ++ncnt;
    bool nf = f;
    if (!f && i < lmt) nf = 1;
    ret += rek(ncnt, pos+1, nf);
  }
  return ret;
}

void solve() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  cout << rek(0,0,0);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
