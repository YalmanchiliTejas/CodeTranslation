#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 1020000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
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
ll pcount(ll x) {return __builtin_popcountll(x);}
const int mod = 1e9 + 7;
//const int mod = 998244353;

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

int main(){
	int n; cin >> n;
	mint s = 0;
	vl a(n); rep(i,n) cin >> a[i], s += a[i];
	mint ans = 0;
	rep(i,n){
		ans += (s - a[i]) * a[i];
	}
	ans /= 2;
	cout << ans.value() << "\n";
}