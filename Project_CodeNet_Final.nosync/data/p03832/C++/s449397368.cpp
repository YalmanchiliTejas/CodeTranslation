#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//constexpr ll mod = 998244353;
constexpr ll mod = 1e9+7;
const double PI = acos(-1.0);
mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());

// Mod int
inline ll minv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a/b;
    swap(a -= t*b, b); swap(u -= t*v, v);
  }
  return (u%m+m)%m;
}

struct mint {
    ll x;
    mint():x(0){}
    mint(ll x):x((x%mod+mod)%mod){}
    mint& fix() { x = (x%mod+mod)%mod; return *this;}
    mint operator-() const { return mint(0) - *this;}
    mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
    mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
    mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
    mint& operator/=(const mint& a){ (x*=minv(a.x, mod))%=mod; return *this; }
    mint operator+(const mint& a)const{ return mint(*this) += a;}
    mint operator-(const mint& a)const{ return mint(*this) -= a;}
    mint operator*(const mint& a)const{ return mint(*this) *= a;}
    mint operator/(const mint& a)const{ return mint(*this) /= a;}
    bool operator<(const mint& a)const{ return x < a.x;}
    bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}

vector<mint> fact(1001);

mint mod_pow(mint a, long long x) {
  mint res = 1;
  while(x > 0) {
    if (x & 1) res = res * a;
    a = a * a; x >>= 1;
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  mint dp[n+1][n+1];

  rep(i, n+1) {
    rep(j, n+1) {
      dp[i][j] = 0;
    }
  }

  for(int i=0; i<a; i++) {
    dp[i][0] = 1;
  }

  fact[0] = 1;
  for(int i=1; i<=1000; i++) fact[i] = fact[i-1]*i;

  for(int i=a; i<=b; i++) {
    for(int j=0; j<=n; j++) {
      dp[i][j] = dp[i-1][j];
      mint fik = mod_pow(fact[i],c);
      for(int k=c; k<=d; k++) {
        int s = j-i*k;
        if (s<0) break;
        dp[i][j] += dp[i-1][s]*fact[n-s]/(fik*fact[n-j]*fact[k]);
        fik *= fact[i];
      }
    }
  }
  cout << dp[b][n] << endl;
}