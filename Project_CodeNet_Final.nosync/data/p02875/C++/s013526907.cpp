#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
//#define ll __int128
//#define int ll
//#define int ll
//#define char ll
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
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
#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";


template <class T0, class T1>
inline ostream & operator << (ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template <class T0, class T1>
inline istream & operator >> (istream &in, pair<T0, T1> &a) {
    return in >> a.first >> a.second;
}

template <class T0, class T1, class T2>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template <class T0, class T1, class T2, class T3>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " <<  get<3>(a) << "}";
}

template<class T>
inline ostream & operator << (ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())
        out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void smain();



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifdef MAX_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#endif
    cout << setprecision(4) << fixed;
    smain();
#ifdef MAX_HOME
    cout << "\n\n\n\nTOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

const int N = 1e7 + 10;
const int M = 998244353;

int pw(int a, int n = M - 2) {
    int ret = 1;
    while (n) {
        if (n & 1)
            ret = (ll) ret * a % M;
        a = (ll) a * a % M;
        n >>= 1;
    }
    return ret;
}

int fact[N], rfact[N];

int ncr(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return (ll) fact[n] * rfact[k] % M * rfact[n - k] % M;
}
void init() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (ll) i * fact[i - 1] % M;
    }
    rfact[N - 1] = pw(fact[N - 1]);
    for (int i = N - 2; i >= 0; --i) {
        rfact[i] = (ll) (i + 1) * rfact[i + 1] % M;
    }
}

int naive(int n) {
    n >>= 1;

    int ans = 0;
    fori (a0, n + 1) {
        fori (b0, n - a0 + 1) {
            int c0 = n - a0 - b0;
            fori (a1, n + 1) {
                fori (b1, n + 1 - a1) {
                    int c1 = n - a1 - b1;
                    bool ok = 1;
                    ok &= max(0, a0 - a1) + max(0, b0 - b1) <= c1;
                    ok &= max(0, a1 - a0) + max(0, b1 - b0) <= c0;
                    if (ok) {
                        int cur = (ll) fact[n] * rfact[a0] % M * rfact[b0] % M * rfact[c0] % M;
                        cur = (ll) cur * fact[n] % M * rfact[a1] % M * rfact[b1] % M * rfact[c1] % M;
                        ans = (ans + cur) % M;
                    }
                }
            }
        }
    }
    return ans;
}

void insum(int & a, int b) {
    a = (a + b) % M;
}

int solve(int n) {
    n >>= 1;

    int ans = pw(3, n * 2);
    for (int x = n + 1; x <= n * 2; ++x) {
        int cur = 2LL * ncr(n * 2, x) * pw(2, n * 2 - x) % M;
        ans = (ans + M - cur) % M;
    }
    return ans;
}

void smain() {
    init();
    int n;
    cin >> n;


//    cout << naive(n) << endl;
    cout << solve(n);
}