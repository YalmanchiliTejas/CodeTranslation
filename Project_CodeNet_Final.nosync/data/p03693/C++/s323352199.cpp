//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS



/**
using std::max; using std::swap; using std::abs; using std::priority_queue; using std::queue; using std::bitset; using std::make_tuple;
using std::istream; using std::ostream; using std::fixed; using std::greater; using std::tuple; using std::tie; using std::make_pair;
using std::cout; using std::cerr; using std::endl; using std::lower_bound; using std::upper_bound; using std::deque; using std::min;
using std::map; using std::string; using std::fill; using std::copy; using std::sort; using std::unique; using std::unordered_set;
using std::multiset; using std::nth_element; using std::min_element; using std::max_element; using std::vector; using std::set;
using std::unordered_map; using std::pair; using std::next_permutation; using std::reverse; using std::rotate; using std::cin;
using std::iota; using std::function; using std::shuffle; using std::iter_swap;

int const INF = 100 + (int) 1e9;
ll const INFL = 100 + (ll) 1e18;
const ll INF = 1e18;

*/

typedef long double ld;
typedef unsigned int uint;
typedef complex<double> P;
typedef unsigned char byte;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
//typedef vector<vb> vvb;

const ll moder = 1e9+7;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG
  #define VALUE(x)
  #define debug(...)
#endif

// nichijou

// data type
#define fi first
#define se second
#define _1 first
#define _2 second

// STL container
#define ALL(a) (a).begin(), (a).end()
#define All(s) (s).begin(),(s).end()
#define rAll(s) (s).rbegin(),(s).rend()
#define CLR(a) a.clear()
#define BK(a) (a.back())
#define FT(a) (a.front())
#define DB(a) a.pop_back()
#define DF(a) a.pop_front()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define mp make_pair
#define pb push_back

#define REP(i,a,b) for (int i(a), _B(b); i < _B; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1), _B(b); i >= _B; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
#define DO(n) REP(__i,0,n)

#define FO(x, n) for (int x = 0; x < n; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define FOR(i,a,b) for(int _b=(b),(i)=(a);(i)<_b;++(i))
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
//#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define ROF(i,b,a) for(int _a=(a),i=(b);i>_a;--i)
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define FOR_ITER(x, a) for(auto (x) = (a).begin(); (x) != (a).end(); ++(x))
#define REPN(i,n) FORN(i,1,n)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)



#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)

#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))

#define ALLA(arr,sz) arr,arr+sz
#define SZ(X) ((int)(X).size())
#define SIZE(X) ((int)(X).size())
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue<T>
#define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
#define IO(){ios_base::sync_with_stdio(0);cin.tie(0);}
#define nl '\n'
#define cint1(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
#define cout1(a) cout<<(a)<<endl
#define cout2(a,b) cout<<(a)<<" "<<(b)<<endl
#define cout3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {}
	template<typename T, typename ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		switch (*s) {
			case '(':
			case '[':
			case '{':
				++c;
				break;
			case ')':
			case ']':
			case '}':
				--c;
				break;
		}
	}
	cerr<<" = "<<a;
	if (*s) {
		cerr<<", ";
		_BG(++s,b...);
	} else
		cerr<<endl;
}
#define BG(...) do { \
	cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
	_BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)

/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define RI(a) RD(a)
#define RII(a,b) RI(a); RI(b)
#define RIII(a,b,c) RI(a); RII(b,c)
#define RIIII(a,b,c,d) RI(a); RIII(b,c,d)

#define DRI(a) int a; RD(a)
#define DRII(a,b) RI(a); RI(b)
#define DRIII(a,b,c) RI(a); RII(b,c)
#define DRIIII(a,b,c,d) RI(a); RIII(b,c,d)

#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)


/* For it's time for you to fulfill your output. */
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
void PT(const double a) {printf("%.16f", a);}
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}

/* The line will last forever! */
template<char sep = ' ',char end = '\n'>
void PL(void) {if (end) PT(end);}
template<char sep = ' ',char end = '\n',typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}

/* Good Luck && Have Fun ! */

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s);
  RP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s);
  RP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

template<typename T> T min(vector<T>& v) {return *min_element(v.begin(), v.end());}

template<typename T> T max(vector<T>& v) {return *max_element(v.begin(), v.end());}

template<typename T> int min_element(vector<T>& v) {return min_element(v.begin(), v.end()) - v.begin();}

template<typename T> int max_element(vector<T>& v) {return max_element(v.begin(), v.end()) - v.begin();}

template<typename T> void sort(vector<T>& v) {sort(v.begin(), v.end());}

template<typename T, typename Function> void sort(vector<T>& v, Function func) {sort(v.begin(), v.end(), func);}

template<typename T> void rsort(vector<T>& v) {sort(v.rbegin(), v.rend());}

template<typename T> void reverse(vector<T>& v) {reverse(v.begin(), v.end());}

template<typename T> void unique(vector<T>& v) {v.erase(unique(v.begin(), v.end()), v.end());}

template<typename T> void nth_element(vector<T>& v, int n) {nth_element(v.begin(), v.begin() + n, v.end());}

template<typename T> bool next_permutation(vector<T>& v) {return next_permutation(v.begin(), v.end());}

template<typename T> int find(vector<T>& v, T t) {return find(v.begin(), v.end(), t) - v.begin();}

template<typename T> int in(vector<T> v, T t) {return find(v, t) != (int)v.size();}

template<typename T> int lower_bound(vector<T>& v, T t) {return lower_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> int upper_bound(vector<T>& v, T t) {return upper_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> T accumulate(const vector<T>& v, function<T(T, T)> func = plus<T>()) {return accumulate(v.begin(), v.end(), T(), func);}

template<typename T> void adjacent_difference(vector<T>& v) {adjacent_difference(v.begin(), v.end(), v.begin());}

template<typename T> void adjacent_difference(vector<T>& v, vector<T>& u) {adjacent_difference(v.begin(), v.end(), u.begin());}

template<typename T> void partial_sum(vector<T>& v, vector<T>& u) {partial_sum(v.begin(), v.end(), u.begin());}

template<typename T> T inner_product(vector<T>& v, vector<T>& u) {return inner_product(v.begin(), v.end(), u.begin(), T(0));}

template<typename T> int count(const vector<T>& v, T t) {return count(v.begin(), v.end(), t);}

template<typename T, typename Function> int count_if(const vector<T>& v, Function func) {return count_if(v.begin(), v.end(), func);}

template<typename T, typename Function> void remove_if(vector<T>& v, Function func) {v.erase(remove_if(v.begin(), v.end(), func), v.end());}

template<typename T, typename Function> bool any_of(vector<T> v, Function func) {return any_of(v.begin(), v.end(), func);}

template<typename T> vector<T> subvector(vector<T>& v, int a, int b) {return vector<T>(v.begin() + a, v.begin() + b);}

template<typename T> int kinds(const vector<T>& v) {return set<T>(v.begin(), v.end()).size();}

template<typename T> void iota(vector<T>& v) {iota(v.begin(), v.end(), T());}

template<typename T> bool is_sorted(const vector<T>& v) {return is_sorted(v.begin(), v.end());}

template<typename Weight, typename Value> Value knapsack(Weight maxWeight, const vector<Weight>& weight, const vector<Value>& value) {
  vector<Value> dp1(maxWeight + Weight(1)), dp2(maxWeight + Weight(1));
  for (size_t i = 0; i < weight.size(); ++i) {
    for (int w = 0; w <= maxWeight; ++w) {
      Weight ww = Weight(w) + weight[i];
      Value vv = dp1[w] + value[i];
      if (ww <= maxWeight && dp2[ww] < vv) dp2[ww] = vv;
    }
    dp1 = dp2;
  }
  return dp1[maxWeight];
}

template<typename Weight, typename Value = long long> vector<Value> knapsackCount(Weight maxWeight, const vector<Weight>& weight) {
  vector<Value> dp1(maxWeight + Weight(1)), dp2(maxWeight + Weight(1));
  dp1[0] = dp2[0] = 1;
  for (auto& w : weight) {
    for (int i = 0; i <= maxWeight; ++i) {
      Weight ww = Weight(i) + w;
      if (ww <= maxWeight) dp2[ww] += dp1[i];
    }
    dp1 = dp2;
  }
  return dp1;
}

template<typename Weight> vector<bool> knapsackFill(Weight maxWeight, const vector<Weight>& weight) {
  vector<bool> dp1(maxWeight + Weight(1)), dp2(maxWeight + Weight(1));
  dp1[0] = dp2[0] = true;
  for (auto& w : weight) {
    for (int i = 0; i <= maxWeight; ++i) {
      Weight ww = Weight(i) + w;
      if (ww <= maxWeight && dp1[i]) dp2[ww] = true;
    }
    dp1 = dp2;
  }
  return dp1;
}

//int main() {
//  int64_t n, a, res = 0;
//  cin >> n >> a;
//  vector<int> x(n);
//  cin >> x;
//  vector<int> y, z;
//  for (int i : x) {
//    if (i >= a) y.emplace_back(i - a);
//    else z.emplace_back(a - i);
//  }
//  auto yy = knapsackCount(2500, y);
//  auto zz = knapsackCount(2500, z);
//  for (int i = 0; i <= 2500; ++i) res += yy[i] * zz[i];
//  cout << res - 1 << endl;
//}



inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

//ll rnd(ll x, ll y) { static auto gen = std::bind(std::uniform_int_distribution<ll>(), std::mt19937); return gen() % (y - x + 1) + x; }

bool is_prime(ll x) { if (x <= 1) return 0; for (ll y = 2; y * y <= x; ++y) if (x % y == 0) return 0; return 1; }

ll sqr(int a) { return (ll) a * a; } ld sqr(ld a) { return a * a; } ll sqr(ll a) { return a * a; }

ll gcd(ll a, ll b) { while (b > 0) { ll t = a % b; a = b; b = t; } return a; }

long long  int nCm(long long int n, long long int m) {
	if (m == 1) {
		return n;
	}
	else {
		return n*nCm(n - 1, m - 1) / m;
	}
}

long long int npm(long long int n,long long int m) {
	if (m == 1) {
		return n;
	}
	else
		if (m == 0) {
			return 1;
		}else {
		return n*npm(n, m - 1);
	}
}


template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}

template<class Int, Int mod>
class ModInt {
public:
	Int x;
	ModInt(): x(0) {}
	ModInt(int a, bool m=1) { if(m) {x=a%mod; if(x<0)x+=mod;} else x=a; }
	ModInt(LL  a, bool m=1) { if(m) {x=a%mod; if(x<0)x+=mod;} else x=a; }
	inline ModInt &operator+=(ModInt that) { if((x += that.x) >= mod) x -= mod; return *this; }
	inline ModInt &operator-=(ModInt that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	inline ModInt &operator*=(ModInt that) { x = LL(x) * that.x % mod; return *this; }
	inline ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
	inline ModInt operator-() const { return ModInt(-this->x); }
	ModInt inverse() const {LL a=x,b=mod,u=1,v=0;while(b){LL t=a/b;a-=t*b;u-=t*v;swap(a,b);swap(u,v);} return ModInt(u);}
	inline friend ostream& operator << (ostream &out, ModInt m) {return out << m.x;}

#define op(o1,o2) ModInt operator o1(ModInt that) const { return ModInt(*this) o2 that; }
	op(+,+=) op(-,-=) op(*,*=) op(/,/=)
#undef op
#define op(o) bool operator o(ModInt that) const { return x o that.x; }
	op(==) op(!=) op(<) op(<=) op(>) op(>=)
#undef op
};

typedef ModInt<int,moder> Mint;

#define MAXN (300005)

Mint F[MAXN];
Mint FI[MAXN];

Mint Cnr(int n, int r)
{
	if(r < 0 || r > n) return 0;
	return F[n] * FI[r] * FI[n-r];
}
// spnauT

//end of jonathanirvings' template v3.0.3 (BETA)

//ll si(int i) {
//    return (ll)i * (i + 1) / 2;
//}
//
//ll multModer(ll l1, ll l2) {
//    return (l1 * l2) % moder;
//}
//
//ll addModer(ll l1, ll l2) {
//    return (l1 + l2) % moder;
//}



    const int DIM = 5e1 + 5;

    long long dp[DIM][DIM * DIM];

int main(){
    IO();

    cint3(r, g, b);
    int sum = g * 10 + b;

    if (sum % 4 == 0)
        cout1("YES");
    else
        cout1("NO");

//	F[0] = 1;
//	FOR(i,1,MAXN) F[i] = F[i-1] * i;
//	FI[MAXN-1] = F[MAXN-1].inverse();
//	ROF(i,MAXN-2,-1) FI[i] = FI[i+1] * (i+1);
//
//	cint2(H,W);
//	cint2(A,B);

//	Mint sol;
//	FOR(i,B+1,W+1) sol += Cnr(i-1+H-A-1, i-1) * Cnr(A-1+W-i, A-1);
//
//	cout << sol << nl;



//    LL C[55][55];

//    C[0][0] = 1;
//    FORN(i,1,50)
//    {
//        C[i][0] = C[i][i] = 1;
//        FOR(j,1,i) C[i][j] = C[i-1][j-1] + C[i-1][j];
//    }
//

//        long double avg0 = (long double) accumulate(ns.rbegin(), ns.rbegin() + i, 0ll) / i;
//        if (avg - avg0 > 1e-6) {
//            break;
//        }

//    printf("%.6Lf\n%lld\n", avg, rs);

	return 0;
}

/**

//#include <fcntl.h>

void solve() {
}

int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);

    cout.precision(15);
    cout << fixed;
    cerr.precision(6);
    cerr << fixed;

    solve();

#ifdef LOCAL
    cerr << "time: " << (ll) clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
#endif
}

*/

/**

#define SORT(v) sort(v.begin(), v.end())
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cmath>
#include <numeric>
#include <utility>

// #include "ane.cpp"

#define INF (int)1e9
#define INFLL (long long)1e18
#define NMAX 100005
#define MMAX 100005
#define MOD 100000
using namespace std;

// コメントアウトするとdebug()を実行しない
// #define DEBUG





//
//  ライブラリ
//

// frequent used aliases
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, int> lp;
typedef pair<ll, ll> llp;
typedef vector<int> vec;
typedef vector<vec> mat;

// frequent used constants
static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

// デバッグ用printf
void debug(const char* format, ...){
    #ifndef DEBUG
    return;
    #endif
    va_list arg;
    va_start(arg, format);
    vprintf(format, arg);  // コンソールに出力
    va_end(arg);
}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// Union-Find Tree
class UnionFindTree{
    struct node{
        int par;
    };
    std::vector<node> T;

    public:
    void init(int num){
        T.resize(num+1);    // ignore T[0]
        for (int i = 1; i <= num; ++i)
        {
            T[i].par = i;
        }
    }
    void unite(int x, int y){
        T[find(y)].par = find(x);
    }
    int find(int x){
        if (T[x].par == x) return x;
        else return T[x].par = find(T[x].par);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

// Segment Tree for Range Minimum Query
    // **********************************************************
    // *** important: all functions' variable,                ***
    // *** such as "index", "l", "r", etc., must be 0-origin. ***
    // **********************************************************
    // ********************************************
    // *** important: NMAX must be power of 2. ***
    // ********************************************
template<typename T>
class SegmentTree{
    private:
    ll N;
    T INF_VAL;
    T dat[NMAX * 2]; // 0 origin, A[i] = dat[i + N]

    T _query(ll l, ll r, ll l_resp, ll r_resp, ll i_dat){
        debug("query(%lld, %lld, %lld, %lld, %lld) called\n",
            l, r, l_resp, r_resp, i_dat);
        if (r < l_resp || r_resp < l) return INF_VAL;
        else if(l <= l_resp && r_resp <= r) return dat[i_dat];
        else return min(_query(l ,r, l_resp, (l_resp + r_resp) / 2, i_dat * 2),
                        _query(l, r, (l_resp + r_resp) / 2 + 1, r_resp, i_dat * 2 + 1));
    }

    public:
    void init(ll _N, T _inf_val){
        N = 1; while(N < _N) N *= 2;
        INF_VAL = _inf_val;
        Fill(dat, _inf_val);
    }
    T get(ll index){
        return dat[index + N];
    }
    void set(int index, T val){
        int i_dat = index + N;
        dat[i_dat] = val;
        for (i_dat /= 2; i_dat > 0; i_dat /= 2)
        {
            dat[i_dat] = min(dat[i_dat * 2], dat[i_dat * 2 + 1]);
        }
    }
    T query(ll l, ll r){
        return _query(l, r, 0, N - 1, 1);
    }
    void dump(){
        cout << "*** SegTree dump begin ***\n";
        cout << "N = " << N << ", INF_VAL = " << INF_VAL << endl;
        for (int i = 1; i < N * 2; i *= 2)
        {
            for (int j = i; j < i * 2; ++j)
            {
                if(dat[j] == INF_VAL) cout << "INF ";
                else cout << dat[j] << " ";
            }
            cout << endl;
        }
        cout << "*** SegTree dump end ***\n";
    }
};

// Binary Indexed Tree for Range Sum Query
    // *******************************************
    // *** important: all functions' variable, ***
    // *** such as "i", must be 1-origin.      ***
    // *******************************************
template<typename T>
class BinaryIndexedTree{
    private:
    ll N;
    T dat[NMAX + 1]; // 1 origin, A[i] = sum(i) - sum(i-1)

    public:
    void init(ll _N){
        N = _N;
        Fill(dat, 0);
    }
    void add(int i, T val){
        while(i <= N) {
            dat[i] += val;
            i += i & -i;
        }
    }
    T sum(ll i){
        T ret = 0;
        while(i > 0) {
            ret += dat[i];
            i -= i & -i; // set last HIGH bit to LOW
        }
        return ret;
    }
    T sum(ll left, ll right){
        return sum(right) - sum(left - 1);
    }
    void dump(){
        cout << "*** BITree dump begin ***\n";
        cout << "N = " << N << endl;
        for (int i = 1; i <= N; i *= 2)
        {
            cout << dat[i] << " ";
        }
        cout << "*** BITree dump end ***\n";
    }
};

//
// ライブラリ終了
//



*/
