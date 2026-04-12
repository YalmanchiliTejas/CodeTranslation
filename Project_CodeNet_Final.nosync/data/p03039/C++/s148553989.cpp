#include <bits/stdc++.h>
using namespace std;
 
#define INIT() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)
#define ForLL(i, s, t) for (LL i = LL(s); i <= LL(t); ++i)
#define rForLL(i, t, s) for (LL i = LL(t); i >= LL(s); --i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define rforeach(i,c) for (__typeof(c.rbegin()) i = c.rbegin(); i != c.rend(); ++i)
 
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
 
#define LOWBIT(x) ((x)&(-x))
 
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
 
#define ms0(a) memset(a,0,sizeof(a))
#define msI(a) memset(a,inf,sizeof(a))
#define msM(a) memset(a,-1,sizeof(a))

#define MP make_pair
#define PB push_back
#define ft first
#define sd second
 
template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}
 
template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)
        in >> x;
    return in;
}
 
template<typename T1, typename T2>
ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]" << "\n";
    return out;
}

inline int gc(){
	static const int BUF = 1e7;
	static char buf[BUF], *bg = buf + BUF, *ed = bg;
	
	if(bg == ed) fread(bg = buf, 1, BUF, stdin);
	return *bg++;
} 

inline int ri(){
	int x = 0, f = 1, c = gc();
	for(; c<48||c>57; f = c=='-'?-1:f, c=gc());
	for(; c>47&&c<58; x = x*10 + c - 48, c=gc());
	return x*f;
}
 
typedef long long LL;
typedef unsigned long long uLL;
typedef pair< double, double > PDD;
typedef pair< int, int > PII;
typedef pair< string, int > PSI;
typedef set< int > SI;
typedef vector< int > VI;
typedef vector< PII > VPII;
typedef map< int, int > MII;
typedef pair< LL, LL > PLL;
typedef vector< LL > VL;
typedef vector< VL > VVL;
const double EPS = 1e-10;
const LL inf = 0x7fffffff;
const LL infLL = 0x7fffffffffffffffLL;
const LL mod = 1e9 + 7;
const int maxN = 2e5 + 7;
const LL ONE = 1;
const LL evenBits = 0xaaaaaaaaaaaaaaaa;
const LL oddBits = 0x5555555555555555;

LL fac[maxN];
void init_fact() {
	fac[0] = 1;
	For(i, 1, maxN - 1) {
		fac[i] = (i * fac[i - 1]) % mod;
	}
}

//ax + by = gcd(a, b) = d
// 扩展欧几里德算法
/**
 *	a*x + b*y = 1
 *	如果ab互质，有解
 *	x就是a关于b的逆元
 *	y就是b关于a的逆元
 *	 
 *	证明： 
 *		a*x % b + b*y % b = 1 % b
 *		a*x % b = 1 % b
 *		a*x = 1 (mod b)
 */
inline void ex_gcd(LL a, LL b, LL &x, LL &y, LL &d){
    if (!b) {d = a, x = 1, y = 0;}
    else{
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}

// 求a关于p的逆元，如果不存在，返回-1 
// a与p互质，逆元才存在 
inline LL inv_mod(LL a, LL p = mod){
    LL d, x, y;
    ex_gcd(a, p, x, y, d);
    return d == 1 ? (x % p + p) % p : -1;
}

inline LL comb_mod(LL m, LL n) {
	LL ret;

	if(m > n) swap(m, n);
	
	ret = (fac[n] * inv_mod(fac[m], mod)) % mod;
	ret = (ret * inv_mod(fac[n - m], mod)) % mod;
	
	return ret;
}

void add_mod(LL &a, LL b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
}

int N, M, K;
LL ans;

int main(){
	INIT(); 
	init_fact();
	cin >> N >> M >> K;
	LL cnt = comb_mod(K - 2, N * M - 2);
	
	ForLL(d, 1, N - 1) {
		add_mod(ans, cnt * ((d * M * M * (N - d)) % mod));
	}
	ForLL(d, 1, M - 1) {
		add_mod(ans, cnt * ((d * N * N * (M - d)) % mod));
	}
	cout << ans << endl;
    return 0;
}