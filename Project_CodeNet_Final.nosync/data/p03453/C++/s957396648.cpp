#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1); i >= (b); --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
#define DO(n) RP(__i,n)
template<class T,class U>
bool cmax(T & a, const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a, const U & b) {return b < a ? a = b, 1 : 0;}

// data type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second

// STL container
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define CLR(a) (a).clear()
#define BK(a) ((a).back())
#define FT(a) ((a).front())
#define DB(a) (a).pop_back()
#define DF(a) (a).pop_front()
#define PB push_back
#define EB emplace_back

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {cerr<<s<<endl;};
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		for (char x : "([{") c += *s == x;
		for (char x : ")]}") c -= *s == x;
	}
	cerr<<" = "<<a;
	if (sizeof...(b)) {
		cerr<<", ";
        ++s;
    }
    _BG(s,b...);
}
#define BG(...) do { \
	cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
	_BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)

/* Reading input is now 20% cooler! */
bool RD() {return 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<class T, class ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DR(T,...) T __VA_ARGS__; RD(__VA_ARGS__)
#define RI(...) DR(int,__VA_ARGS__)

/* For it's time for you to fulfill your output. */
void PT(const char & a) {putchar(a);}
void PT(char const * const & a) {fputs(a, stdout);}
void PT(const double & a) {printf("%.16f", a);}
void PT(const int & a) {printf("%d", a);}
void PT(const ll & a) {printf("%lld", a);}

/* The line will last forever! */
template<char s = ' ', char e = '\n'>
void PL() {if (e) PT(e);}
template<char s = ' ', char e = '\n', class T, class ... TT>
void PL(const T & a, const TT & ... b)
{PT(a); if (sizeof...(b) && s) PT(s); PL<s,e>(b...);}

/* Good Luck && Have Fun ! */
const int N = 1e5 + 87, M = 1e9 + 7;
const ll inf = 1e18;
vector<pii> g[N];
ll add(ll a,ll b) {return (a+=b) < M ? a : a - M;}
ll sub(ll a,ll b) {return (a-=b) < 0 ? a + M : a;}
ll mul(ll a,ll b) {return a * b % M;}
ll sqr(ll a) {return mul(a,a);}
void sp(ll de[],ll way[],int n,int s)
{
    fill_n(de,n,inf);
    fill_n(way,n,0);
    de[s] = 0;
    way[s] = 1;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    while (SZ(pq)) {
        ll w,u;
        tie(w,u) = pq.top();
        pq.pop();
        if (de[u] < w)
            continue;
        for (const auto & p : g[u]) {
            int v = p.F;
            w = de[u] + p.S;
            if (w <= de[v]) {
                if (w < de[v]) {
                    de[v] = w;
                    way[v] = 0;
                    pq.push({w,v});
                }
                way[v] = add(way[v], way[u]);
            }
        }
    }
}
#define ws popopopopopop
ll ds[N], dt[N], ws[N], wt[N];
int main()
{
    RI(n,m,s,t);
    --s, --t;
    RP(i,m) {
        RI(u,v,d);
        --u, --v;
        g[u].PB({v,d});
        g[v].PB({u,d});
    }
    sp(ds,ws,n,s);
    sp(dt,wt,n,t);
    ll ans = sqr(ws[t]);
    RP(i,n)
        if (ds[i] == dt[i] && ds[i] * 2 == ds[t])
            ans = sub(ans, sqr(mul(ws[i], wt[i])));
    RP(u,n) {
        for (const auto & p : g[u]) {
            int v,w;
            tie(v,w) = p;
            if (ds[u] + w + dt[v] == ds[t] && ds[u] * 2 < ds[t] && dt[v] * 2 < ds[t])
                ans = sub(ans, sqr(mul(ws[u], wt[v])));
        }
    }
    PL(ans);
}
