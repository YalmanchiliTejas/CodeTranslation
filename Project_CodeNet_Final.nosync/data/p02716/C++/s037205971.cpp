#include <bits/stdc++.h>

/* snippet: useful macros and functions */
#define ARC(i, a, b) for(Int i = (a); i < (b); ++i)
#define RC(i, n) ARC(i, 0, n)
#define ARCH(i, a, b) for(Int i = (a) - 1; i >= (b); --i)
#define RCH(i, n) ARCH(i, n, 0)
template<class T> T ant(const T &a, const T &b){ return a > b ? a : b; }
template<class T> T ont(const T &a, const T &b){ return a < b ? a : b; }
template<class T> T rng(const T &a, const T &b){ return a < b ? b - a : a - b; }
template<class T> void th(T &a, const T &b, T (*f)(const T &, const T &)){ a = f(a, b); }
#define anth(a, b) th(a, b, ant)
#define onth(a, b) th(a, b, ont)

/* snippet: modint library */
template<class T, int MOD>
class Modint{
	T val;
public:
	Modint(T val = 0) : val(val) {}
	operator T(){ return val; }
	Modint &operator+=(const Modint &a){ val += a.val; if(val >= MOD) val -= MOD; return *this; }
	Modint &operator-=(const Modint &a){ val -= a.val; if(val < 0) val += MOD; return *this; }
	Modint &operator*=(const Modint &a){ val = val * a.val % MOD; return *this; }
	void inverse(){T x[2]={MOD,val},a[2]={0,1};int i;for(i=0;x[!i];i^=1){a[i]-=x[i]/x[!i]*a[!i];x[i]=x[i]%x[!i];}if(!i)a[i]+= MOD;val=a[i];}
	Modint &operator/=(Modint a){ a.inverse(); return *this *= a; }
	friend Modint modpow(Modint a, int n){ Modint ret(1); while(n){ if(n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
	friend Modint operator+(Modint a, const Modint &b){ return a += b; }
	friend Modint operator-(Modint a, const Modint &b){ return a -= b; }
	friend Modint operator*(Modint a, const Modint &b){ return a *= b; }
	friend Modint operator/(Modint a, const Modint &b){ return a /= b; }
	friend std::ostream &operator<<(std::ostream &os, const Modint &a){ return os << a.val; }
};

/* snippet: using declarations */
using Int = long long;
using std::cout;
using std::cin;
using std::endl;
using Mint = Modint<long long, 1000000007>;

Int n;
Int a[212345];
Int dp[2][212345];

int main(){
	cin >> n;
	RC(i, n){
		cin >> a[i];
	}

	if(n % 2 == 0){
		dp[0][n - 1] = 0;
		dp[1][n - 1] = a[n - 1];
		RCH(i, n - 1){
			if(i % 2 == 0){
				dp[0][i] = ant(dp[0][i + 2] + a[i], dp[1][i + 1]);
			}else{
				dp[0][i] = ant(dp[0][i + 2] + a[i], dp[0][i + 1]);
				dp[1][i] = dp[1][i + 2] + a[i];
			}
		}
		cout << dp[0][0] << endl;
	}else{
		dp[0][n - 1] = 0;
		dp[1][n - 1] = a[n - 1];
		dp[0][n - 2] = 0;
		dp[1][n - 2] = ant(a[n - 1], a[n - 2]);
		RCH(i, n - 2){
			if(i % 2 == 0){
				dp[0][i] = ant(dp[0][i + 2] + a[i], dp[1][i + 1]);
				dp[1][i] = dp[1][i + 2] + a[i];
			}else{
				dp[0][i] = ant(dp[0][i + 2] + a[i], dp[0][i + 1]);
				dp[1][i] = ant(dp[1][i + 2] + a[i], dp[1][i + 1]);
			}
		}
		cout << dp[0][0] << endl;
	}
}
