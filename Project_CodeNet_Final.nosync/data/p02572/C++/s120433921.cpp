#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

// auto mod int
// depends on Template

const int mod = 1000000007;
//const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

/*累積和
query(l,r)=引数に渡したvectorにおける[l,r)の和(0-indexed)
verified : https://judge.yosupo.jp/problem/static_range_sum
*/

template<typename T>
struct CumulativeSum{
    vector<T> res;
    CumulativeSum(const vector<T> vec){//初期化
        int sz = vec.size();
        res.resize(sz+1,0);
        for(int i=0;i<=sz;i++){
            res[i+1] = res[i]+vec[i];
        }
    }

    T query(int l, int r){
        return res[r]-res[l];
    }
};

int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<mint>r(n+1,0);
    rep(i,n){
        r[i+1]=r[i]+a[i];
    }
    mint ans = 0;
    rep(i,n){
        mint tmp = a[i];
        tmp *= r[n]-r[i+1];
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}