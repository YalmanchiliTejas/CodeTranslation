#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	#define NDEBUG
#endif
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
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

template<long long MOD>
class ModInt {
public:
	const static long long mod = MOD;
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

template<long long MOD> ostream& operator<< (ostream& os, const ModInt<MOD>& m) { os << m.get(); return os; }
template<long long MOD> istream& operator>> (istream& is, ModInt<MOD>& m){ long long n; is >> n; m = n; return is;}
typedef ModInt<1000000007> mint;



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
	LL n, m, k;
	while(cin >> n >> m >> k) {
		mint ans = 0;
		ConvQuery co(n * m + 10);
		FOR(len, 1, n) {
			LL num = n - len;
			ans += co(n * m - 2, k - 2) * m * m * len * num; 
		}
		FOR(len, 1, m) {
			LL num = m - len;
			ans += co(n * m - 2, k - 2) * n * n * len * num; 
		}
		cout << ans << endl;
	}
	return 0;
}
