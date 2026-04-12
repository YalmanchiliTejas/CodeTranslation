#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 100;
const long double EPS = 1e-10;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<int> c(26, INF);
  rep(i, n) {
    int m = s[i].size();
    vector<int> cnt(26, 0);
    rep(j, m) {
      cnt[s[i][j] - 'a']++;
    }
    rep(j, 26) {
      c[j] = min(c[j], cnt[j]);
    }
  }

  rep(i, 26) {
    char ch = 'a' + i;
    rep(j, c[i]) {
      cout << ch;
    }
  }
  cout << endl;


  
  return 0;
}