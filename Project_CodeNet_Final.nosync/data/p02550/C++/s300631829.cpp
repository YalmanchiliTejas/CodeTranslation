#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

ll check[110000];

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vll v;
  ll cnt = 0LL;
  ll a = x;
  rep(i,m*2) {
    v.push_back(a);
    cnt += a;
    check[a] = true;
    a *= a;
    a %= m;
    if(check[a]) break;
    if(a==0) {
      cout << cnt << endl;
      return 0;
    }
  }
  ll ans = 0LL;
  bool swi = true;
  vll vv;
  rep(i,v.size()) {
    if(v[i]==a) swi = false;
    if(swi) {
      ans += v[i];
      n--;
    }
    else vv.push_back(v[i]);
  }
  ll s = vv.size();
  ll sum = 0LL;
  rep(i,s) sum += vv[i];
  ans += sum*(n/s);
  rep(i,n%s) ans += vv[i];
  cout << ans << endl;
  return 0;
}
