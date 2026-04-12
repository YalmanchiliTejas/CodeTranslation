#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ll = long long int;
using vec = vector<int>;
using P = pair<int,int>;
const int INF = 1e9+7;

int main() {
  ll n, x, m; cin >> n >> x >> m;
  vec c(m, -1);
  vector<ll> a(m+2);
  int s, e;
  a[0] = x;
  for (int i = 1; i < m+2; i++) {
    a[i] = a[i-1] * a[i-1] % m;
    if (c[a[i]] == -1) c[a[i]] = i;
    else {
      s = c[a[i]];
      e = i;
    }
  }

  int y = (n-s) / (e-s); //繰り返し回数
  int z = (n-s) % (e-s); //最後のあまり個数
  ll sa = 0, sb = 0, sc = 0;
  rep(i, s) {
    sa += a[i];
  }
  for (int i = s; i < e; i++) {
    sb += a[i];
  }
  for (int i = s; i < s+z; i++) {
    sc += a[i];
  }

  cout << sa + sb*y + sc << endl;
}
