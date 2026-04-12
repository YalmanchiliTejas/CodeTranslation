#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()

const int INF = 1001001001;

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

mint modPow(mint a, int n){
  //cout << a << endl;
  if(n == 0) return 1;
  if(n == 1) return a;
  if(n % 2) return a * modPow(a, n-1);
  else return modPow(a*a, n/2);
}

const int MAX = 200200;


int main(){
	vector<mint> fact(2000005);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); i++){
		fact[i] = fact[i-1] * i;
	}		
	const auto comb = [&fact](int n, int r) {
		return fact[n] / fact[r] / fact[n-r];
	};
	ll n, m, k; cin >> n >> m >> k;
	mint t = 0, tt = 0;
	for (int i = 1; i < m; i ++) t += (mint) n * n * (m-i) * 2 * i;
	for (int i = 1; i < n; i ++) tt += (mint) m * m * (n-i) * 2 * i;
	t *= comb(k, 2) * fact[m*n-2] / fact[k] / fact[m*n-2 - (k-2)];
	tt *= comb(k, 2) * fact[m*n-2] / fact[k] / fact[m*n-2 - (k-2)];
	cout << (t+tt) << endl;
}