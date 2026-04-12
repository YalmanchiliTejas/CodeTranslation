#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)

int n;
ll x;
vector<ll> a(51), p(51);

ll f(ll n, ll x) {
  // 1つ目のn-1のバーガーに届いていない場合
  if (n == 0) {
    return (x <= 0 ? 0 : 1);
  // 1つ目のn-1のバーガーに届いている場合
  } else if (x <= 1+a[n-1]) {
    return f(n-1, x-1);
  // 2つ目のn-1のバーガーに届いている場合
  } else {
    return p[n-1]+1 + f(n-1, x-2-a[n-1]);
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  cin >> n >> x;

  a[0] = 1;
  p[0] = 1;
  rep(i, n) {
    a[i+1] = a[i]*2+3;
    p[i+1] = p[i]*2+1;
  }

  cout << f(n, x) << endl;
}
