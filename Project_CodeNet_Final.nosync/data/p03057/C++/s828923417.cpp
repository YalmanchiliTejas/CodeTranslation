#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
//#define ll __int128
#define int ll
//#define char ll
#define double ld
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cerr << (#x) << " = " << (x) << endl;

#ifdef MAX_HOME
#define cerr cout
#else
#define cerr if (false) cerr
#endif

const double PI = 2 * acos(0.0);
//#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";


template<class T0, class T1>
inline ostream &operator<<(ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template<class T0, class T1>
inline istream &operator>>(istream &in, pair<T0, T1> &a) {
    return in >> a.first >> a.second;
}

template<class T0, class T1, class T2>
inline ostream &operator<<(ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template<class T0, class T1, class T2, class T3>
inline ostream &operator<<(ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " << get<3>(a) << "}";
}

template<class T>
inline ostream &operator<<(ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void smain();


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef MAX_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef MAX_HOME
    cout << "\n\nTOTAL EXECUTION TIME: " << float(clock() - start) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

const int M = 1e9 + 7;

void solve_fib(int n) {
    vi f(n + 1);
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % M;
    }
    cout << (f[n] + f[n - 2]) % M;
}
const int oo = 1e9 + 10;

int kek(int cnt, bool & first) {
    if (first) {
        first = false;
        if (cnt & 1)
            return cnt;
        return cnt + 1;
    }
    if (cnt & 1)
        return cnt;
    return oo;
}

void insum(int &a, int b) {
    a = (a + b) % M;
}

void smain() {

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    m = s.size();
    if (count(ALL(s), 'R') == 0 || count(ALL(s), 'B') == 0) {
        solve_fib(n);
        return;
    }

    vi a(m);
    fori (i, m) {
        a[i] = s[i] == 'R';
    }

    vi min_sz(2, oo);
    int cur = -1;
    int cnt = 0;
    bool first = true;
    for (auto c : a) {
        if (c != cur) {
            if (cur != -1) {
                inmin(min_sz[cur], kek(cnt, first));
            }
            cur = c;
            cnt = 1;
        } else {
            cnt++;
        }
    }
    min_sz[!a[0]] = 1;
    vvi f(2);
    fori (z, 2) {
        vvi dp(2, vi(n, 0));
        vvi p(2, vi(n, 0));
        p[!z][0] = dp[!z][0] = 1;
        for (int i = 1; i < n; ++i) {
            fori (zz, 2) {
                if (min_sz[zz] == oo) {
                    dp[zz][i] = (p[!zz][i - 1] + (i - 2 >= 0 ? p[!zz][i - 2] : 0));
                } else {
                    int j = i - min_sz[zz];
                    dp[zz][i] = (p[!zz][i - 1] - (j - 2 >= 0 ? p[!zz][j - 2] : 0) + M) % M;
                }
            }
            fori (zz, 2) {
                p[zz][i] = (dp[zz][i] + (i - 2 >= 0 ? p[zz][i - 2] : 0)) % M;
            }
        }
        f[z] = dp[z];
    }
    int ans = 0;
    fori (z, 2) {
        for (int sz = 1; sz <= min(n - 1, min_sz[z]); sz += 1 + (min_sz[z] != oo)) {
            insum(ans, (ll)f[!z][n - sz] * sz % M);
        }
    }
    cout << ans;
}