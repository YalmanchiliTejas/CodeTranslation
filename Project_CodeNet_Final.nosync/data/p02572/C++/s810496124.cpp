#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int mod = 1000000007;

ll mmod(ll a) {
  a %= mod;
  if (a < 0) a += mod;
  return a;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll k = 0;
  rep(i,0,n) {
    cin >> a[i];
    k += a[i];
    k %= mod;
  }
  ll ans = 0;
  rep(i,0,n-1) {
    k = mmod(k-a[i]);
    ans += k * a[i];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
