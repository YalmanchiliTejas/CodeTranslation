#include <bits/stdc++.h>
// #include <experimental/iterator>

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

/* debug */
// auto debug = std::experimental::make_ostream_joiner(std::cout, " ");

/* snippet: modint library */
template<class T, int MOD>
class Modint{
	T val;
public:
	Modint(T val = 0) : val(val % MOD + (val > 0 ? 0 : MOD)) {}
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

Int a, b, c, x, y;

int main(){
	cin >> a >> b >> c >> x >> y;
	Int ab = ont(a + b, c * 2);
	onth(a, c * 2);
	onth(b, c * 2);
	Int ans;
	if(x < y){
		ans = x * ab + (y - x) * b;
	}else{
		ans = y * ab + (x - y) * a;
	}
	cout << ans << endl;
}
