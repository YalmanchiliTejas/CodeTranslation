#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

#define INF 1001001001
#define MAX 1e18

const int mod = 998244353;

int main() {
  ll n;
  int x, m;
  cin >> n >> x >> m;
  vector<int> used(m,-1);
  vector<ll> a(m);
  a[0] = x;
  ll ans = 0;
  int lpst = -1, lped = -1;
  for (ll i = 0; i < n; i++) {
    used[a[i]] = i;
    ans += a[i];
    a[i+1] = a[i]*a[i]%m;
    if (used[a[i+1]]!=-1) {
      lpst = used[a[i+1]];
      lped = i;
      n -= lped+1;
      break;
    }
  }
  if (lpst == -1) {
    cout << ans << endl;
    return 0;
  }
  ll sum = 0;
  int cnt = 0;
  for (int i = lpst; i <= lped; i++) {
    sum += a[i];
    cnt++;
  }

  ans += sum*(n/cnt);
  for (int i = lpst; i < lpst+n%cnt; i++) ans += a[i];
  cout << ans << endl;
  return 0;
}
