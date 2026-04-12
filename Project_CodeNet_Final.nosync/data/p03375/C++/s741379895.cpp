#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

// Problem Specific Parameter:

class ModInt {
public:
	static unsigned int MOD;
	ModInt(): x(0) {}
	ModInt(signed y) : x(y >= 0 ? y % MOD : MOD - (-y) % MOD) {}
	ModInt(signed long long y) : x(y >= 0 ? y % MOD : MOD - (-y) % MOD) {}


	// Arithmetic Oprators
	ModInt &operator+=(ModInt that) {
		if ((x += that.x) >= MOD) x -= MOD; 
		return *this;
	}
	ModInt &operator-=(ModInt that) {
		if ((x += MOD - that.x) >= MOD) x -= MOD; 
		return *this;
	}
	ModInt &operator*=(ModInt that) {
		x = 1LL * x * that.x % MOD;
		return *this;
	}
	ModInt &operator/=(ModInt that) {
		return *this *= ModInt(get<1>(extgcd(that.x, int(MOD))));
	}
	ModInt &operator%=(ModInt that) {
		x %= that.x;
		return *this;
	}

	ModInt &operator+=(const int that) { return *this += ModInt(that);}
	ModInt &operator-=(const int that) { return *this -= ModInt(that);}
	ModInt &operator*=(const int that) { return *this *= ModInt(that);}
	ModInt &operator/=(const int that) { return *this /= ModInt(that);}
	ModInt &operator%=(const int that) { return *this %= ModInt(that);}

	// Comparators
	bool operator <(ModInt that) { return x < that.x; }
	bool operator >(ModInt that) { return x > that.x; }
	bool operator<=(ModInt that) { return x <= that.x; }
	bool operator>=(ModInt that) { return x >= that.x; }
	bool operator!=(ModInt that) { return x != that.x; }
	bool operator==(ModInt that) { return x == that.x; }

	// Utilities
	unsigned getval() const { return x;}
	ModInt operator+(ModInt that) const { return ModInt(*this) += that;}
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that;}
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that;}
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that;}
	ModInt operator%(ModInt that) const { return ModInt(*this) %= that;}
	ModInt operator+(const int that) const { return ModInt(*this) += that;}
	ModInt operator-(const int that) const { return ModInt(*this) -= that;}
	ModInt operator*(const int that) const { return ModInt(*this) *= that;}
	ModInt operator/(const int that) const { return ModInt(*this) /= that;}
	ModInt operator%(const int that) const { return ModInt(*this) %= that;}
	ModInt operator=(const int that) { return *this = ModInt(that);}
	friend istream &operator>>(istream& is, ModInt &that) {ll tmp; is >> tmp; that = ModInt(tmp);return is;}
	friend ostream &operator<<(ostream& os, const ModInt &that) { return os << that.x; }
	
	ModInt power(ll n) const {
		ll b = 1LL, a = x;
		while(n){
			if(n & 1) b = b * a % MOD;
			a = a * a % MOD;
			n >>= 1;
		}
		return ModInt(b);
	}
private:
	unsigned x;
	
	inline tuple<int, int, int> extgcd(int a, int b) {
		if (b == 0) return make_tuple(a, 1, 0);
		tuple<int, int, int> ret = extgcd(b, a % b);
		swap(get<1>(ret), get<2>(ret));
		get<2>(ret) -= a / b * get<1>(ret);
		return ret;
	}
};

unsigned int ModInt::MOD = 2;
using mint = ModInt;
const mint ZERO = mint(0);
const mint ONE = mint(1);


ll idx_power(ll x, ll n) {
	ll b = 1LL, a = x;
	while(n){
		if(n & 1) b = b * a % (ModInt::MOD - 1);
		a = a * a % (ModInt::MOD - 1);
		n >>= 1;
	}
	return b;
}

const int limit = 3010;
mint C[limit][limit];
mint dp[limit][limit];
mint tmp[limit];

int main(void){
	ll n;
	cin >> n >> ModInt::MOD;

	rep(i,n+1)rep(j,i+1){
		if(j == 0 or j == i)
			C[i][j] = ONE;
		else
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	}

	dp[0][0] = ONE;
	rep(i,1,n+1)rep(j,1,i+1) dp[i][j] = dp[i-1][j-1] + mint(j) * dp[i-1][j];


	rep(k,n+1){
		mint coef = mint(2).power(idx_power(2,n-k));
		rep(x,k+1){
			mint cur = (dp[k][x] + dp[k][x+1] * (x + 1)) * mint(2).power((n-k) * x);
			cur *= coef;
			tmp[k] += cur;
		}
	}

	mint ans = ZERO;
	rep(i,n+1){
		mint cur = C[n][i] * tmp[i];
		if(i & 1)
			ans -= cur;
		else
			ans += cur;
	}
	
	cout << ans << endl;
	
	return 0;
}