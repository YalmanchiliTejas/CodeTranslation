#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
const ll mod = 1e9+7;
const ll INF = 1e18;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;
using V = vector<ll>;
using P = pair<ll,ll>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> roop(m);
  ll ans = 0;
  vector<ll> a(100000);
  bool bo = true;
  rep(i,n) {
    if (roop[x] > 0 && bo) {
      ll sy = a[i]-a[roop[x]-1];
      ans += sy * ((n-i)/(i-(roop[x]-1)));
      i += ((n-i)/(i-(roop[x]-1))) * (i-(roop[x]-1));
      i--;
      bo = false;
    }
    else {
      ans += x;
      if (bo) {
        a[i+1] = a[i] + x;
        roop[x] = i+1;
      }
      x = x*x%m;
    }
  }
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}