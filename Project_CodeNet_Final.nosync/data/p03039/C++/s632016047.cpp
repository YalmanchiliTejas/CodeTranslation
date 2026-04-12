#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define lint long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) ((int)v.size())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MINF(a) memset(a,0x3f,sizeof(a))
#define POW(n) (1LL<<(n))
#define POPCNT(n) (__builtin_popcount(n))
#define IN(i,a,b) (a <= i && i <= b)
using namespace std;
template <typename T> inline bool CHMIN(T& a,T b) { if(a>b) { a=b; return 1; } return 0; }
template <typename T> inline bool CHMAX(T& a,T b) { if(a<b) { a=b; return 1; } return 0; }
template <typename T> inline void SORT(T& a) { sort(ALL(a)); }
template <typename T> inline void REV(T& a) { reverse(ALL(a)); }
template <typename T> inline void UNI(T& a) { sort(ALL(a)); a.erase(unique(ALL(a)),a.end()); }
template <typename T> inline T LB(vector<T>& v, T a) { return *lower_bound(ALL(v),a); }
template <typename T> inline int LBP(vector<T>& v, T a) { return lower_bound(ALL(v),a) - v.begin(); }
template <typename T> inline T UB(vector<T>& v, T a) { return *upper_bound(ALL(v),a); }
template <typename T> inline int UBP(vector<T>& v, T a) { return upper_bound(ALL(v),a) - v.begin(); }
template <typename T1, typename T2> ostream& operator<< (ostream& os, const pair<T1,T2>& p) { os << p.first << " " << p.second; return os; }
template <typename T1, typename T2> istream& operator>> (istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }
template <typename T> ostream& operator<< (ostream& os, const vector<T>& v) { REP(i,v.size()) { if (i) os << " "; os << v[i]; } return os; }
template <typename T> istream& operator>> (istream& is, vector<T>& v) { for(T& in : v) is >> in; return is; }
template <typename T = int> vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...)); }
template <typename T, typename V> typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) { t = v; }
template <typename T, typename V> typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) { for(auto &e : t) fill_v(e,v); }
const lint MOD = 1000000007;
const lint INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;

const int SIZE_COMB = 200010;
long long inv[SIZE_COMB];
long long fac[SIZE_COMB];
long long finv[SIZE_COMB];

void init(int n = SIZE_COMB) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i < n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// nCk (階乗 + 逆元)
// n < 10^7, k < 10^7, n,k < MOD, MOD: 素数
// 前計算 O(n) 時間
// 本計算 O(1) 時間
long long nCk(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n - k] % MOD;
}

int calc(int n, int m, int k) {
    int res = 0;
    FOR(i, 1, m) {
        int tmp = i;
        (tmp *= (m - i)) %= MOD;
        (tmp *= n * n % MOD) %= MOD;
        (res += tmp) %= MOD;
    }
    (res *= nCk(n * m - 2, k - 2)) %= MOD;
    return res;
}

void _main() {
    init();
    int N, M, K;
    cin >> N >> M >> K;
    cout << (calc(N, M, K) + calc(M, N, K)) % MOD << endl;
}

signed main(signed argc, char **argv) {
    if (argc > 1) {
        if (strchr(argv[1], 'i'))
            freopen("input.txt", "r", stdin);
        if (strchr(argv[1], 'o'))
            freopen("output.txt", "w", stdout);
    }
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    _main();
    return 0;
}