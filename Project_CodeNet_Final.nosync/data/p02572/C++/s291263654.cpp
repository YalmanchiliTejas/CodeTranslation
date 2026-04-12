#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rep2(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define rev(i, n) for (int (i) = (n)-1; (i) >= 0; (i)--)
#define rev2(i, a, b) for (int (i) = (a)-1; (i) >= (b); (i)--)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pll = pair<long long, long long>;
template<class T> using Vec = vector<T>;
template<class T> using VVec = vector<vector<T>>;
long long TEN(int i) {return !i ? 1 : TEN(i-1)*10LL;}
template<class T, class U> 
bool chmin(T& a, const U& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T, class U> 
bool chmax(T& a, const U& b) {if (a < b) {a = b; return 1;} return 0;}
 
struct IoSetup {
  	IoSetup() {
    	cin.tie(nullptr);
    	ios::sync_with_stdio(false);
    	cout << fixed << setprecision(10);
  	}
} iosetup;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template<long long mod>
class ModInt {
public:
	long long v;
	ModInt(long long v = 0) : v((v % mod + mod) % mod) {}
	ModInt operator+(ModInt t) {return ModInt((v + t.v) % mod);}
	ModInt operator-(ModInt t) {return ModInt((v - t.v + mod) % mod);}
	ModInt operator*(ModInt t) {return ModInt((v * t.v) % mod);}
	ModInt operator+=(ModInt t) {return *this = *this + t;} 
	ModInt operator-=(ModInt t) {return *this = *this - t;}
	ModInt operator*=(ModInt t) {return *this = *this * t;}
	ModInt operator-() {return ModInt(-v);}
	ModInt mpow(long long t) {
		if (t == 0) return ModInt(1);
		ModInt a = mpow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}
	ModInt inv() {mpow(mod - 2);}
	ModInt operator/(ModInt t) {return ModInt(v) * t.inv();}
	ModInt operator/=(ModInt t) {return *this = *this / t;}
	ModInt operator==(ModInt t) {return *this.v == t.v;}
	ModInt operator!=(ModInt t) {return *this.v != t.v;}
	friend ostream& operator<<(ostream& os, const ModInt& mi) {
		os << mi.v;
		return os;
	}
};

using mint = ModInt<1000000007>;

// ans = mod_pow(a, b, (ll)MOD);
template< typename T >
T mod_pow(T x, T n, const T &p) {
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
}


int main() {
	int N;
	cin >> N;
	ll A[N];
	rep (i, N) cin >> A[i];

	mint sum = 0;
	rep (i, N) sum += mint(A[i]);

	

	mint ans = mint(0);
	rep (i, N) ans += (mint(A[i])) * (sum - mint(A[i]));


	ll aaa = ans.v;
	aaa = aaa * mod_pow(2LL, 1000000005LL, 1000000007LL) % 1000000007LL;
	
	cout << aaa << endl; 
	
	return 0;
}
