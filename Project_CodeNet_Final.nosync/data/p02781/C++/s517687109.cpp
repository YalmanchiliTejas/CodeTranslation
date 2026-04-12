#include <bits/stdc++.h>
//#include <experimental/iterator>

/* snippet: useful macros and functions */
#define ARC(i, a, b) for(Int i = (a); i < (b); ++i)
#define RC(i, n) ARC(i, 0, n)
#define ARCH(i, a, b) for(Int i = (a) - 1; i >= (b); --i)
#define RCH(i, n) ARCH(i, n, 0)
#define ALL(v) v.begin(), v.end()
template<class T> T rng(const T &a, const T &b){ return a < b ? b - a : a - b; }
template<class T> void chmaxmin(T &a, const T &b, const T &(*f)(const T &, const T &)){ a = f(a, b); }
#define chmax(a, b) chmaxmin(a, b, std::max)
#define chmin(a, b) chmaxmin(a, b, std::min)

/* debug */
// auto debug = std::experimental::make_ostream_joiner(std::cout, " ");

/* snippet: inf struct */
/*
struct{ template<class T> constexpr operator T(){ return std::numeric_limits<T>::max(); } constexpr auto operator-(); } inf;
struct{ template<class T> constexpr operator T(){ return std::numeric_limits<T>::lowest(); } constexpr auto operator-(); } negative_inf;
constexpr auto decltype(inf)::operator-(){ return negative_inf; }
constexpr auto decltype(negative_inf)::operator-(){ return inf; }
*/

/* snippet: modint library */
#if __cpp_concepts
template<std::signed_integral T, T MOD>
#else
template<class T, T MOD>
#endif
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

/* push n numbers and get i-th min */
/* to get min and 2nd min, declare K_th_min<T, 2> and use get<0>(), get<1>() */
/*
template<class T, std::size_t K>
class K_th_min{
	friend class K_th_min<T, K + 1>;
	T val;
	K_th_min<T, K - 1> lower;
	void push_(T &x){ lower.push_(x); if(val > x) std::swap(val, x); }
public:
	K_th_min() : val(std::numeric_limits<T>::max()) {}
	void push(T x){ push_(x); }
	template<std::size_t I> T get(){ if constexpr(I == K - 1) return val; else return lower.template get<I>(); }
};
template<class T> class K_th_min<T, 0>{ friend class K_th_min<T, 1>; void push_(T &){} public: K_th_min(){} void push(T){} };
*/

/* snippet: using declarations */
using Int = long long;
using std::cout;
using std::cin;
using std::endl;
using Mint = Modint<long long, 1000000007>;

Int ans(std::string n, Int k){
	if(k == 1){
		return 9 * (n.size() - 1) + (n[0] - '0');
	}else if(k == 2){
		Int ret = 81 * (n.size() - 1) * (n.size() - 2) / 2 + (n[0] - '1') * 9 * (n.size() - 1);
		int i = n.find_first_not_of('0', 1);
		if(i != std::string::npos) ret += ans(n.substr(i), 1);
		return ret;
	}else if(k == 3){
		Int ret = 729 * (n.size() - 1) * (n.size() - 2) * (n.size() - 3) / 6 + (n[0] - '1') * 81 * (n.size() - 1) * (n.size() - 2) / 2;
		int i = n.find_first_not_of('0', 1);
		if(i != std::string::npos) ret += ans(n.substr(i), 2);
		return ret;
	}
}

int main(){
	std::string n;
	Int k;
	cin >> n >> k;
	cout << ans(n, k) << endl;
}
