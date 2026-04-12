#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に
//cout << fixed << setprecision(15);

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), s(n);
  rep(i, n) {
    cin >> a[i];
    a[i] %= 1000000007;
    s[i] = (i == 0) ? a[0] : (s[i-1] + a[i]);
    s[i] %= 1000000007;
  }

  ll ans = 0;
  for(int i = 1; i < n; i++) {
    ans += (a[i] * s[i-1]) % 1000000007;
  }

  cout << ans % 1000000007 << endl;
}