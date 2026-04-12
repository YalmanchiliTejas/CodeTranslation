#include <bits/stdc++.h>

using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldbl;
typedef pair<int, int> pii;
typedef pair<uint, uint> puu;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<uint> vu;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<puu> vpuu;
typedef vector<pll> vpll;
typedef vector<pull> vpull;
typedef vector<string> vstr;
typedef vector<double> vdbl;
typedef vector<ldbl> vldbl;
#define pb push_back
#define ppb pop_back
#define pfr push_front
#define ppfr pop_front
#define emp emplace
#define empb emplace_back
#define be begin
#define rbe rbegin
#define all(x) (x).be(), (x).end()
#define rall(x) (x).rbe(), (x).rend()
#define fir first
#define sec second
#define mkp make_pair
#define brif(cond) if (cond) break
#define ctif(cond) if (cond) continue
#define retif(cond) if (cond) return
void canhazfast() {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}
template<typename T> T gcd(T a, T b) {return b ? gcd(b, a%b) : a;}
template<typename T> T extgcd(T a, T b, T &x, T &y)
{
    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
    while (b) {
        T q = a/b; a %= b; swap(a, b);
        x0 -= q*x1; swap(x0, x1);
        y0 -= q*y1; swap(y0, y1);
    }
    x = x0; y = y0; return a;
}
int ctz(uint x) {return __builtin_ctz(x);}
int ctzll(ull x) {return __builtin_ctzll(x);}
int clz(uint x) {return __builtin_clz(x);}
int clzll(ull x) {return __builtin_clzll(x);}
int popcnt(uint x) {return __builtin_popcount(x);}
int popcntll(ull x) {return __builtin_popcountll(x);}
int bsr(uint x) {return 31^clz(x);}
int bsrll(ull x) {return 63^clzll(x);}

#define MOD 1000000007
//#define MOD 998244353

uint add(uint a, uint b) { return a+b < MOD ? a+b : a+b-MOD; }
uint sub(uint a, uint b) { return a < b ? a+MOD-b : a-b; }
uint mul(uint a, uint b) { return (ull)a*b%MOD; }
uint sqr(uint a) { return mul(a, a); }

uint modpow(uint b, uint e)
{
    uint r = 1;
    for (; e; e >>= 1) {
        if (e&1) r = mul(r, b);
        b = mul(b, b);
    }
    return r;
}

uint modinv(uint n) { return modpow(n, MOD-2); }
uint moddiv(uint n, uint d) { return mul(n, modinv(d)); }

#define MX 200016

uint fac[MX];

uint tri(uint x) { return mul(mul(x, x+1), (MOD+1)/2); }
uint binom(uint n, uint k) { return moddiv(fac[n], mul(fac[k], fac[n-k])); }

int main()
{
    canhazfast();

    int n, m, k, nm;
    uint sdi = 0, sdj = 0, ans = 0;

    cin >> n >> m >> k;
    nm = n*m;
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= nm; ++i) fac[i] = mul(fac[i-1], i);
    for (int di = 1; di < n; ++di) {
        uint w = mul(sqr(m), mul(n-di, di));
        sdi = add(sdi, w);
    }
    //cerr << "sdi = " << sdi << '\n';
    for (int dj = 1; dj < m; ++dj) {
        uint w = mul(sqr(n), mul(m-dj, dj));
        sdj = add(sdj, w);
    }
    //cerr << "sdj = " << sdj << '\n';
    ans = add(sdi, sdj);
    ans = mul(ans, binom(nm-2, k-2));
    cout << ans << '\n';

    return 0;
}
