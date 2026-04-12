#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        srand(time(NULL));
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cout.precision(12);
    };
} fastIO_;

// debugger
class Debugger {
   public:
    template <typename T>
    Debugger &operator<<(const T &v) {
        cerr << v;
        return *this;
    }
    ~Debugger() { cerr << endl; }
};

template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
    bool first = true;
    os << "[";
    for (auto &v : a) {
        if (!first)
            os << ", ";
        os << v;
        first = false;
    }
    os << "]";
    return os;
}

template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
    bool first = true;
    os << "[";
    for (unsigned int i = 0; i < v.size(); i++) {
        if (!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &v) {
    bool first = true;
    os << "{";
    for (typename set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "}";
}

template <typename T>
inline ostream &operator<<(ostream &os, const multiset<T> &v) {
    bool first = true;
    os << "{";
    for (typename multiset<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "}";
}

template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
    bool first = true;
    os << "[";
    for (typename map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}
#define dbg(...) Debugger() << "[DEBUG] " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " "

// types
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define si set<int>
#define mpii map<int, int>
#define pii pair<int, int>
#define pll pair<ll, ll>

// names
#define pb push_back
#define fi first
#define se second
#define mp(a, b) make_pair((a), (b))
#define sz(a) ((int)(a).size())
#define rep(i, s, t) for (int i = (s); i < (t); i++)
#define repn(i, s) for (int i = 0; i < (s); i++)
#define ms(a, b) memset(a, b, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

// constants
const ll MOD = 998244353;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

// functions
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll power_mod(ll x, ll y, ll p) {
    // calculate x^y % p
    ll ans = 1;
    x %= p;
    while (y > 0) {
        if (y & 1) ans = (ans * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ans;
}

inline ll modInverse(ll n, ll p) {
    // Returns n^(-1) mod p
    return power_mod(n, p - 2, p);
}

//  vll fac(n + 1, 1);
//  for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
ll nCrModP(vll &fac, ll n, ll r, ll p) {
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p *
            modInverse(fac[n - r], p) % p) %
           p;
}

template <typename T>
void print_vector(const vector<T> &v) {
    repn(i, sz(v)) {
        if (i > 0)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

// =====================================================================================================================
#define maxn 100005

int n, m;

void readAndInit() {
    // cin >> n;
}

bool solve() {
    return n >= 30;
}

void solve(int _cas) {
    readAndInit();
    auto ans = solve();
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    // cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
#endif

    // int cas;
    // cin >> cas;
    // repn(i, cas) solve(i + 1);

    while (cin >> n) solve(1);
}
