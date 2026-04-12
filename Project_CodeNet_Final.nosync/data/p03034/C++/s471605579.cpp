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
typedef multimap< int, int > MMII;
typedef unordered_map< int, int > uMII;
typedef pair< LL, LL > PLL;
typedef vector< LL > VL;
typedef vector< VL > VVL;
typedef priority_queue< int > PQIMax;
typedef priority_queue< int, VI, greater< int > > PQIMin;
const double EPS = 1e-10;
const LL inf = 0x7fffffff;
const LL infLL = 0x7fffffffffffffffLL;
const LL mod = 1e9 + 7;
const int maxN = 1e5 + 7;
const LL ONE = 1;
const LL evenBits = 0xaaaaaaaaaaaaaaaa;
const LL oddBits = 0x5555555555555555;

int N, s[maxN];
LL ans;

int main(){
	INIT(); 
	cin >> N;
	Rep(i, N) cin >> s[i];
	
	For(i, 1, N - 3) { // 枚举 A - B 
		LL ret = 0;
		For(k, 1, (N - 1) / i) {
			LL tmp = N - 1 - i * k;
			if(tmp <= i || tmp % i == 0 && tmp / i <= k) break;
			ret += s[i * k] + s[tmp];
			ans = max(ans, ret);
		}
	}
	
	cout << ans << endl;
    return 0;
}
