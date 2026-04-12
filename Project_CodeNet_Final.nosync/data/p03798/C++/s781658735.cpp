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
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  int n;
  string s;
  cin >> n >> s;

  rep(i, 4) {
    vector<char> c(n, 'a');
    if (i <= 1) c[0] = 'S';
    else c[0] = 'W';
    if (i & 1) c[1] = 'W';
    else c[1] = 'S';

    bool flag = true;

    rep(j, n) {
      char res;
      if (c[(j + 1) % n] == 'S' && s[(j + 1) % n] == 'o') res = c[j];
      else if (c[(j + 1) % n] == 'W' && s[(j + 1) % n] == 'x') res = c[j];
      else if (c[(j + 1) % n] == 'S' && s[(j + 1) % n] == 'x') {
        if (c[j] == 'S') res = 'W';
        else if (c[j] == 'W') res = 'S';
      }
      else if (c[(j + 1) % n] == 'W' && s[(j + 1) % n] == 'o') {
        if (c[j] == 'S') res = 'W';
        else if (c[j] == 'W') res = 'S';
      }

      if (c[(j + 2) % n] == 'a') c[(j + 2) % n] = res;
      else if (c[(j + 2) % n] != res) {
        flag = false;
        break;
      }
    }

    if (flag) {
      rep(i, n) cout << c[i];
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;


  
  return 0;
}