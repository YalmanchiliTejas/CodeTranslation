#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef int Int;
typedef pair<Int,Int> pii;
typedef pair<Int,double> pid;
typedef pair<double,double> pdd;
typedef pair<Int,pii> pip;
typedef pair<double,Int> pdp;
typedef vector<Int> veci;
typedef vector<double> vecd;
typedef vector<int> veci;
typedef vector<double> vecd;
typedef vector<veci> mati;
typedef vector<vecd> matd;
#define A first
#define B second
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (x).size()
#define CLR(x) memset(x,0,sizeof x)
#define pdebug() printf("%d\n",__LINE__)
#define REP(i,a,b) for(int i = (a);i <= (b);i++)
#define FORO(i,n) REP(i,0,(int)n-1)
#define FORI(i,n) REP(i,1,(int)n)
#define FORIT(i,t) for(auto i = t.begin();i != t.end();i++)
#define eps 1e-6
#define sqr(x) ((x)*(x))
#define dist(_a,_b) sqrt(sqr(_a.A-_b.A)+sqr(_a.B-_b.B))
#define norm(_a) sqrt(sqr(_a.A)+sqr(_a.B))
template<typename T>void getMin(T &a,T b) { if(a > b) a = b; }
template<typename T>void getMax(T &a,T b) { if(a < b) a = b; }
template<typename T> vector<T> getVector(const int n) { return vector<T>(n); }
template<typename T> vector<T> getVector(const int n, const T a) { return vector<T>(n, a); }
template<typename T> vector<T> getEmptyVector() { return vector<T>(); }
template<typename T> void appendAll(vector<T> &a, vector<T> b) { a.insert(a.end(), b.begin(), b.end()); }
// #define X first
// #define Y second
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const ll MOD = 1000000007;
const int MAXN = 1<<17;
const int inf = 1<<28;
const int NIL = -inf;
int popcount(int x)  { return __builtin_popcount(x); }
#define DUMP(a) \
    do { std::cout << #a " = " << (a) << ", "; } while(false)
#define DUMPLN(a) \
    do { std::cout << #a " = " << (a) << std::endl; } while(false)

ll modpow(ll a, int k) {
    if(k == 0) return 1;
    if(k & 1) return (modpow(a, k - 1) * a) % MOD;
    else { ll t = modpow(a, k / 2LL); return (t * t) % MOD; }
}

ll mod_inverse(ll a) {
    return modpow(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M, K;
    cin >> N >> M >> K;

    ll comb = 1;
    FORI(k, K - 2) {
        comb = (comb * (((N * M - (ll)k - 1LL) * mod_inverse(k))%MOD))%MOD;
    }
    
    ll ans = 0;
    FORI(y, N) {
        ll tot = 0;
        FORI(x, M) {
            tot += ((x - 1) * y + ((ll)y * (y - 1)) / 2LL) % MOD;
            tot %= MOD;
            ans += ((comb * tot) % MOD) % MOD;
            ans %= MOD;
        }
        tot = 0;
        FORI(x, M) {
            tot %= MOD;
            ans += ((comb * tot) % MOD) % MOD;
            ans %= MOD;
            tot += (x * (N - y) + ((ll)(N - y + 1LL) * (N - y)) / 2LL) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}