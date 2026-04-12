#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	// #define NDEBUG
#endif
#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
template<typename T, typename U> ostream& operator<< (ostream& os, const pair<T,U>& p) { cout << '(' << p.first << ' ' << p.second << ')'; return os; }

template<long long MOD>
class ModInt {
public:
	const static long long mod = MOD;
	long long x;
	
	ModInt() {
		x = 0;
	}

	ModInt(long long x) {
		this->x = x < 0 ? (x+mod)%mod : x%mod;
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

	bool operator==(ModInt that) const { return x == that.get(); }
	bool operator!=(ModInt that) const { return x != that.get(); };
	ModInt operator-() const { return x == 0 ? 0 : ModInt(mod-x); }

};

template<long long MOD> ostream& operator<< (ostream& os, const ModInt<MOD>& m) { cout << m.get(); return os; }
typedef ModInt<1000000007> mint;


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

const LL mod = 1e9+7;

//res.first*a+res.second*b == 1 となるresを返す (a,bは互いに素)
pair<long long, long long> extgcd(long long a,long long b)
{
	if(b==1){
		return pair<long long, long long>(0,1);
	}
	pair<long long, long long> t=extgcd(b,a%b);
	return pair<long long, long long>(t.second,t.first-a/b*t.second);
}

//modの逆元を返す
long long inverse(long long a,long long modl = mod)
{
	return (extgcd(modl,a).second+modl)%modl;
}

//xCyを返す
long long Cinv(long long x, long long y, const long long modl = mod){
	long long n = 1 ,r = 1;
	for(int i = 0; i < y; i++){
		n = n*(i+1)%modl;
		r = r*(x-i)%modl;
	}
	return r*inverse(n,modl)%modl;
}



LL modfac(int n){
	LL res = 1;
	FOR(i,1,n+1){
		res *= i;
		res %= mod;
	}
	return res;
}

int main()
{
	ios_init();
	int n;
	while(cin >> n) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		
		vector<mint> fac(n+1);
		vector<mint> facinv(n+1);
		fac[0] = 1;
		REP(i,n) fac[i+1] = fac[i]*(i+1);
		REP(i,n+1) facinv[i] = fac[i].inverse();

		int m = b-a+1;
		vector<vector<mint>> dp(n+1,vector<mint>(m+1,0));
		REP(j,m+1) dp[0][j] = 1;
		REP(i,n){
			// if((i+1)%a == 0){
			// 	mint c = 1;
			// 	c *= fac[i+1];
			// 	REP(k,(i+1)/a){
			// 		c /= fac[a];
			// 	}
			// 	c /= (i+1)/a;
			// 	dp[i+1][0] = c;
			// }
			FOR(j,1,m+1){ DEBUG(i+1); DEBUG(j);
				mint sum = 0;
				int g = a+j-1;
				DEBUG(g);
				int num = i+1;
				DEBUG(num);
				int k = 0;
				mint com = 1;
				while(num >= 0) {
					// DEBUG(j); DEBUG(num); DEBUG(com);
					if(k == 0 or (c <= k and k <= d)){
						sum += dp[num][j-1]*facinv[k]*com;
						DEBUG(dp[num][j-1]/fac[k]*com);
					}
					num -= g;
					if(num >= 0) com *= fac[num+g]*facinv[num]*facinv[g];
					k++;
				}
				dp[i+1][j] = sum;
			}
		}
		REP(i,n+1) dpite(ALL(dp[i]));
		cout << dp[n][m] << endl;
	}
	return 0;
}
