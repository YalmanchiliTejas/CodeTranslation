#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

vector<ll> fac(MAX), finv(MAX), inv(MAX);

void comInit(){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i=2; i<MAX; i++){
		fac[i] = fac[i-1]*i % mod;
		inv[i] = mod - inv[mod%i] * (mod/i) % mod;
		finv[i] = finv[i-1] * inv[i] % mod;
	}
}


ll com(ll n, ll k){
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

ll modpow(ll x, ll n, ll mod){
	ll res = 1;
	while(n > 0){
		if(n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
	return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
	return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
	return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
	return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
	a += rhs.a;
	if (a >= Modulus) {
	  a -= Modulus;
	}
	return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
	if (a < rhs.a) {
	  a += Modulus;
	}
	a -= rhs.a;
	return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
	a = a * rhs.a % Modulus;
	return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
	u64 exp = Modulus - 2;
	while (exp) {
	  if (exp % 2) {
		*this *= rhs;
	  }
	  rhs *= rhs;
	  exp /= 2;
	}
	return *this;
  }
};

using mint = modint<mod>;

mint dp[1005][1005];

int main(){
	ll n,a,b,c,d; cin >> n >> a >> b >> c >> d;
	dp[a][0] = 1;
	comInit();
	REP(i,a,b+1){
		rep(j,n+1){
			dp[i+1][j] += dp[i][j];
			for(ll k=c; k<=d; k++){
				if(k*i + j > n) break;
				dp[i+1][k*i + j] += dp[i][j] * fac[k*i + j] * finv[j] / modpow(fac[i],k,mod) * finv[k];
			}
		}
	}
	/*rep(i,b+2){
		rep(j,n+1) cout << dp[i][j].value() << " ";
		cout << "\n";
	}*/
	cout << dp[b+1][n].value() << "\n";
}