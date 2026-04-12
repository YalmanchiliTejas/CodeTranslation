#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	#define NDEBUG
#endif
#define _USE_MATH_DEFINES
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif
const int INF = 1e9;
using namespace std;
template<typename T, typename U> ostream& operator<< (ostream& os, const pair<T,U>& p) { os << '(' << p.first << ' ' << p.second << ')'; return os; }

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#ifdef LOCAL111
	#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
	template<typename T> void dpite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
#else
	#define DEBUG(x) true
	template<typename T> void dpite(T a, T b){ return; }
#endif
#define F first
#define S second
#define SNP string::npos
#define WRC(hoge) cout << "Case #" << (hoge)+1 << ": "
template<typename T> void pite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}

typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int,int> P;

void ios_init(){
	//cout.setf(ios::fixed);
	//cout.precision(12);
#ifdef LOCAL111
	return;
#endif
	ios::sync_with_stdio(false); cin.tie(0);
}

using Integer = LL;

Integer modpow(Integer x, Integer y, Integer mod){
	x %= mod;
	y %= mod;
	Integer tmp = x;
	Integer res = 1;
	while(y != 0){
		if(y&1){
			res = res*tmp%mod;
		}
		tmp = tmp*tmp%mod;
		y >>= 1;
	}
	return res;
}



//res.first*a+res.second*b == 1 となるresを返す (a,bは互いに素)
pair<Integer, Integer> extgcd(Integer a,Integer b)
{
	if(b==1){
		return pair<Integer, Integer>(0,1);
	}
	pair<Integer, Integer> t=extgcd(b,a%b);
	return pair<Integer, Integer>(t.second,t.first-a/b*t.second);
}


Integer inverse(Integer a,Integer modl)
{
	return (extgcd(modl,a).second+modl)%modl;
}


LL mod;
LL solve(int n) {
	vector<vector<LL>> dp(n+1, vector<LL>(n+1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			if(j-i >= 0) {
				dp[i][j] = (dp[i-1][j] + dp[i][j-i])%mod;
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	REP(i, n+1) dpite(ALL(dp[i]));
	LL res = 0;
	REP(i, n+1) {
		res += ((i)*dp[i][n]%mod + mod)%mod;
		res %= mod;
	}
	DEBUG(res);
	return res;
}


class ModInt {
public:
	static long long mod;
	long long x;
	
	ModInt() {
		x = 0;
	}

	ModInt(long long x) {
		x %= mod;
		this->x = x < 0 ? x+mod : x;
	}

	int get() const {
		return (int)x;
	}

	ModInt &operator+=(ModInt that) {
		if((x += that.get()) >= mod) x -= mod;
		return *this;
	}

	ModInt &operator-=(ModInt that) {
		if((x += mod-that.get()) >= mod) x -= mod;
		return *this;
	}

	ModInt &operator*=(ModInt that) {
		x = x*that.get()%mod;
		return *this;
	}

	ModInt &operator/=(ModInt that) {
		return *this *= that.inverse();
	}

	ModInt operator+(ModInt that) const {
		return ModInt(*this) += that;
	}

	ModInt operator-(ModInt that) const {
		return ModInt(*this) -= that;
	}

	ModInt operator*(ModInt that) const {
		return ModInt(*this) *= that;
	}

	ModInt operator/(ModInt that) const {
		return ModInt(*this) /= that;
	}

	ModInt inverse() const {
		using std::swap;
		long long a = x, b = mod, u = 1, v = 0;
		while(b) {
			long long t = a/b;
			a -= t*b; swap(a,b);
			u -= t*v; swap(u,v);
		}
		return ModInt(u);
	}

	ModInt pow(int n) const{
		ModInt b = *this;
		ModInt res = 1;
		while(n != 0) {
			if(n&1){
				res *= b;
			}
			b *= b;
			n >>= 1;
		}
		return res;
	}

	bool operator==(ModInt that) const { return x == that.get(); }
	bool operator!=(ModInt that) const { return x != that.get(); }
	ModInt operator-() const { return x == 0 ? 0 : ModInt(mod-x); }
};

ostream& operator<< (ostream& os, const ModInt& m) { os << m.get(); return os; }
istream& operator>> (istream& is, ModInt& m){ long long n; is >> n; m = n; return is;}
using mint = ModInt;
long long mint::mod = 0;

class ConvQuery {
	vector<mint> fac;
	vector<mint> facinv;

public:
	
	ConvQuery(int n) {
		fac = vector<mint>(n+1);
		facinv = vector<mint>(n+1);
		fac[0] = 1;
		facinv[0] = 1;
		for(int i = 0; i < n; ++i) {
			fac[i+1] = fac[i]*(i+1);
			facinv[i+1] = fac[i+1].inverse();
		}
	}

	mint operator()(int n, int m) {
		if(n >= 0 and 0 <= m and m <= n) return fac[n]*facinv[n-m]*facinv[m];
		else return 0;
	}
};


int main()
{
	ios_init();
	int n;
	while(cin >> n >> mint::mod) {
		vector<vector<mint>> dp(n+2, vector<mint>(n+2));
		 // [group][]
		dp[0][0] = 1;
		REP(j, n+1) {
			REP(i, n+1) {
				// dp[i+1][j+1] = dp[i+1][j] * (i+1) + dp[i][j];
				dp[j+1][i+1] = dp[j][i+1] * (i+1) + dp[j][i];
			}
		}
		REP(i, n+2) dpite(ALL(dp[i]));
		// auto ppow = [&](LL x, LL y) -> mint { return modpow(x, modpow(x, y, mint::mod-1), mint::mod); };
		auto get = [&](int n, int x) -> mint {
			return dp[n][x+1] * (x+1) + dp[n][x];
		};
		vector<mint> ppow(n+10);
		REP(i, SZ(ppow)) ppow[i] = modpow(2, modpow(2, i, mint::mod-1), mint::mod);
		// vector<mint> memo(n+1);
		// REP(i, SZ(memo)) memo[i] = modpow(modpow(2, i, mint::mod), n-i, mint::mod);
		
		// choose x group
		auto f = [&](int cn, int x) -> mint {
			return get(cn, x) * modpow(modpow(2, x, mint::mod), n-cn, mint::mod) * ppow[n-cn];
		};
		// auto f = [&](int cn, int x) -> mint {
		// 	return get(cn, x) * modpow(modpow(2, x, mint::mod), n-cn, mint::mod) * ppow(2, n-cn);
		// };
		// auto test = [&](int cn) -> mint {
		// 	mint res = 0;
		// 	REP(mask, 1<<(1<<n)) {
		// 		vector<int> cnt(n);
		// 		REP(mma, 1<<n) {
		// 			if((mask>>mma)&1) {
		// 				REP(i, n) {
		// 					if((mma>>i)&1) {
		// 						cnt[i]++;
		// 					}
		// 				}
		// 			}
		// 		}
		// 		int a = 0;
		// 		REP(i, cn) {
		// 			if(cnt[i] <= 1) {
		// 				a++;
		// 			}
		// 		}
		// 		if(a == cn) res += 1;
		// 	}
		// 	return res;
		// };
		// DEBUG(test(0));
		// {
		// 	mint sum = 0;
		// 	REP(i, n+1) sum += test(i);
		// 	DEBUG(sum);
		// 	DEBUG(ppow(2, n));
		// }

		ConvQuery c(n+10);
		// mint ans = ppow(2, n);
		mint ans = ppow[n];
		// dpite(ALL(ppow));
		FOR(cn, 1, n+1) {
			mint d = 0;
			FOR(k, 0, cn+1) {
				d += f(cn, k);
			}
			d *= c(n, cn);
			// DEBUG(c(n, cn));
			if(cn%2 == 0) {
				d = -d;
			}
			ans -= d;
		}
		cout << ans << endl;
	}
	return 0;
}
