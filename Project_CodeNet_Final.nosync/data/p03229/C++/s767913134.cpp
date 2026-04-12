#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);

  rep(i, n) cin >> a[i];

  sort(a.rbegin(), a.rend());
  ll ans = -1e17;
  if(n % 2 == 1){

    ll tans = 0;
    ll cnt = 0;
    rep(i, n/2-1){
      tans += 2 * a[cnt];
      cnt++;
    }
    tans += a[cnt];
    cnt++;
    tans += a[cnt];
    cnt++;
    rep(i, cnt, n){
      tans += -2 * a[i];
    }

    chmax(ans, tans);

    tans = 0;
    cnt = 0;
    rep(i, n/2){
      tans += 2 * a[cnt];
      cnt++;
    }
    tans += -1 * a[cnt];
    cnt++;
    tans += -1 * a[cnt];
    cnt++;
    rep(i, cnt, n){
      tans += -2 * a[i];
    }

    chmax(ans, tans);

  }else{

    ll tans = 0;
    int cnt = 0;
    rep(i, n/2-1){
      tans += 2 * a[i];
      cnt++;
    }
    tans += a[cnt];
    cnt++;
    tans += -a[cnt];
    cnt++;
    rep(i, cnt, n){
      tans += -2 * a[i];
    }

    chmax(ans, tans);


  }

  cout << ans << endl;

  return 0;
}
