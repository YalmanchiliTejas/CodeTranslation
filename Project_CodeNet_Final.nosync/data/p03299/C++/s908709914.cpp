#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x <<": " << (x) << endl
//Ã¥ï¿½Â¨Ã¦Â¯ï¿½Ã¤Â¸ÂªÃ¥ï¿½Â½Ã¦ï¿½Â°Ã§ï¿½ï¿½Ã¥ï¿½Â¥Ã¥ï¿½Â£Ã¥Â¤ï¿½Ã¦ï¿½Â§Ã¨Â¡ï¿½Ã¤Â¸ï¿½Ã¦Â¬Â¡Ã¯Â¼ï¿½Ã¥ï¿½ÂºÃ¥ï¿½Â£Ã¥Â¤ï¿½Ã¦ï¿½Â§Ã¨Â¡ï¿½Ã¤Â¸ï¿½Ã¦Â¬Â¡Ã£ï¿½ï¿½Ã§ï¿½Â¶Ã¥ï¿½ï¿½Ã¥Â°Â±Ã¥ï¿½Â¯Ã¤Â»Â¥Ã¥Â¿Â«Ã©ï¿½ï¿½Ã¥Â¾ï¿½Ã§ï¿½Â¥Ã¦ï¿½Â¯Ã¥ï¿½ÂªÃ¤Â¸ÂªÃ¥ï¿½Â°Ã¦ï¿½Â¹Ã¦Â®ÂµÃ©ï¿½ï¿½Ã¨Â¯Â¯Ã¤Âºï¿½
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#ifdef LOCAL
#define see(x) cout  << #x << ": " << (x) << endl
#endif
#ifndef LOCAL
#define see(x)
#endif


#define rep(n) for(int _ = 0; _ != (n); ++_)
//#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define Rng(i, n) for(int i = 0; i != (n); ++i)
#define rng(i, a, b) for(int i = (a); i < (b); ++i)
#define RNG(i, a) for(auto &i: (a))
#define dwn(i, r, l) for(int i = (r); i>=(l); i--)

namespace std {
    template<class T>
    T begin(std::pair<T, T> p)
    {
        return p.first;
    }
    template<class T>
    T end(std::pair<T, T> p)
    {
        return p.second;
    }
}


#if __cplusplus < 201402L
template<class Iterator>
    std::reverse_iterator<Iterator> make_reverse_iterator(Iterator it)
    {
        return std::reverse_iterator<Iterator>(it);
    }
#endif

template<class Range>
std::pair<std::reverse_iterator<decltype(begin(std::declval<Range>()))>, std::reverse_iterator<decltype(begin(std::declval<Range>()))>> make_reverse_range(Range &&r)
{
    return std::make_pair(make_reverse_iterator(::begin(r)), make_reverse_iterator(::end(r)));
}

#define RRNG(x, cont) for (auto &x: make_reverse_range(cont))



template<class T> int sign(const T &a) { return a == 0 ? 0 : a > 0 ? 1 : -1; }
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> void Min(T &a, const T &b){ a = min(a, b); }
template<class T> void Max(T &a, const T &b){ a = max(a, b); }

template<typename T> void println(const T &t) { cout << t << '\n'; }
template<typename T, typename ...Args> void println(const T &t, const Args &...rest) { cout << t << ' '; println(rest...); }

template<typename T> void print(const T &t) { cout << t << ' '; }

template<typename T, typename ...Args> void print(const T &t, const Args &...rest) { cout << t; print(rest...); }

// this overload is chosen when there's only one argument
template<class T> void scan(T &t) { cin >> t; }
template<class T, class ...Args> void scan(T &a, Args &...rest) { cin >> a; scan(rest...); }

using ll = long long;
using ull = unsigned long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using pip = pair<int, pii>;
using szt = size_t;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using pli = pair<ll,int>;
using wg = vector<vpii>; //weighted graph

int cas;
const double pi = acos(-1);
ll mod = 1e9 + 7;

template<class T>
inline void add_mod(T &a, const T &b) {
    a += b;
    if (a >= mod) a -= mod;
}
template<class T>
void sub_mod(T &a, const T &b){
    a -= b;
    if (a < 0) a += mod;
}
auto bo=[](int x){ //Ã¤Âºï¿½Ã¨Â¿ï¿½Ã¥ï¿½Â¶Ã¨Â¾ï¿½Ã¥ï¿½Âº
    bitset<5> a(x);
    cout << a << endl;
};



mat operator*(const mat &a, const mat &b) {
    mat c(a.size(), vec(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j]) { // optimization for sparse matrix
                for (int k = 0; k < b[0].size(); k++) {
                    add_mod(c[i][k], a[i][j] * b[j][k] % mod);
                }
            }
        }
    }
    return c;
}

vec operator*(const mat &a, const vec &b) {
    vec c(a.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            add_mod(c[i], a[i][j] * b[j] % mod);
        }
    }
    return c;
}

mat pow(mat a, ull n) {
    mat res(a.size(), vec(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, __int128 T) {
    if (T<0) os<<"-";
    if (T>=10 ) os<<T/10;
    if (T<=-10) os<<(-(T/10));
    return os<<( (int) (T%10) >0 ? (int) (T%10) : -(int) (T%10) ) ;
}

__int128 LPOW(__int128 x, ll n) {
    __int128 res = 1;
    for (; n; n /= 2, x *= x, x %= mod) {
        if (n & 1) {
            res *= x;
            res %= mod;
        }
    }
    return res;
}

ll POW(ll x, ll n){
    ll res = 1;
    for (; n; n /= 2, x *= x, x %= mod) {
        if (n & 1) {
            res *= x;
            res %= mod;
        }
    }
    return res;
}


ll INV(ll x) {
    return POW(x, mod - 2);
}

ll inv(ll x){
    //    see(x);
    return x == 1? 1: (mod - mod/x * inv(mod%x) % mod);
}



// 2D rotation
void rotate(double &x, double &y, double theta) {
    double tx = cos(theta) * x - sin(theta) * y;
    double ty = sin(theta) * x + cos(theta) * y;
    x = tx, y = ty;
}
namespace bit {
    const int BIT_N = 1e5 + 5;

    int bit[BIT_N];

    int sum(int x) {
        int res = 0;
        while (x) {
            res += bit[x];
            x -= x & -x;
        }
        return res;
    }

    int sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int x, int v, int n) {
        while (x <= n) {
            bit[x] += v;
            x += x & -x;
        }
    }
}

namespace util{
    int len(ll x){return snprintf(nullptr, 0, "%lld", x);}
    vi get_d(ll x){
        vi res;
        while(x) {
            res.pb(x%10);
            x /= 10;
        }
        reverse(all(res));
        return res;
    }
    template <class T> T parity(const T &a){
        return a & 1;
    }
    template <class T>
    void out (const vector<T> &a){
        std::copy(a.begin(), a.end(), std::ostream_iterator<T>(std::cout, ", "));
        cout << endl;
    };
    template<class T>
    void lisan(T &a){
        sort(all(a));
        a.erase(unique(all(a)), a.end());
    }
}

using namespace util;

// #include <ext/pb_ds/priority_queue.hpp>

// typedef __gnu_pbds :: priority_queue<pip, less<pip>, __gnu_pbds::thin_heap_tag > Heap;

// Heap h;

// Heap::point_iterator pos[N][N];
const ll LINF = LLONG_MAX/10;
const int INF = INT_MAX/10;
const int M = 3000 + 5;

ll dp[105][105];

int main() {
    // Single Cut of Failure taught me
    cout << std::fixed; //
    cout << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("main.in", "r", stdin);
    //    freopen("main.out", "w", stdout);
#endif
    int n;
    scan(n);
    map<int,int> ls; //离散化
    vi h(n);

    RNG(x, h){
        scan(x);
        ls[x];
    }
    int tmp = 0;
    vi H;
    RNG(x, ls){
        x.second = tmp++;
        H.pb(x.first);
    }

    vi g(n);

    rng(i, 0, n) g[i] = ls[h[i]];

    auto c=[&](int i){
        return i == 0 ? H[0] : H[i] - H[i-1];
    };

    // 不要害怕边界条件！
    rng(j, 0, g[0]+1){
        if(j == 0)
            dp[0][j] = (POW(2, c(j))-2 + mod) % mod * POW(2, h[0] - H[j]) % mod;
        else
            dp[0][j] = 2 * (POW(2, c(j)) -1) % mod * POW(2, h[0] - H[j]) % mod;
    }
    dp[0][g[0]+1] = 2;

    rng(i, 1, n){
        rng(j, 0, g[i]+1){
            if(ls[h[i-1]] >= j){
                dp[i][j] = dp[i-1][j] * POW(2, max(0, h[i]-h[i-1])) % mod;
            }
            else{
                dp[i][j] = dp[i-1][g[i-1]+1] * 2 % mod * (POW(2, c(j)) -1)  % mod * POW(2, h[i]-H[j]) % mod;
            }
        }
        if(g[i-1] <= g[i]){
            dp[i][g[i]+1] = 2 * dp[i-1][g[i-1]+1] % mod;
        }
        else{
            ll sum = 0;
            rng(j, g[i]+1, g[i-1]+2) add_mod(sum, dp[i-1][j]);
            dp[i][g[i]+1] = 2 * sum % mod;
        }
    }
//
//    rng(j, 0, g[1]+2){
//        see(dp[1][j]);
//    }

    ll ans = 0;
    rng(i, 0, g[n-1]+2){
        add_mod(ans, dp[n-1][i]);
    }

    println(ans);

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}