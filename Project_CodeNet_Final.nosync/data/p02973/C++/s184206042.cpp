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
const int INF = 1000000005;
const long double EPS = 1e-10;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i] = -a[i];
  }

  vector<int> c;
  rep(i, n) {
    auto itr = upper_bound(c.begin(), c.end(), a[i]);
    if (itr == c.end()) {
      c.push_back(a[i]);
    }
    else {
      *itr = a[i];
    }
  }

  cout << c.size() << endl;

  
  return 0;
}