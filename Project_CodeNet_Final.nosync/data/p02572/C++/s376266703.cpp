#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
#include <climits>
#include <cfloat>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double l_double;

#define gcd __gcd
#define FFS(var) __builtin_ffs(var)
#define CLZ(var) __builtin_clz(var)
#define CTZ(var) __builtin_ctz(var)
#define POPCOUNT(var) __builtin_popcount(var)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define s_cast static_cast // <>
#define deb(x) cerr << "[" << #x << "] -> [" << x << "] "
#define deb2(x,y) cerr << "[" << #x << ", " << #y << "] -> [" << x << ", " << y << "] "
#define deb3(x,y,z) cerr << "[" << #x << ", " << #y << ", " << #z << "] -> [" << x << ", " << y << ", " << z << "] "
#define debVV(V) cerr << #V << ":\n" << V << endl; // 2D
#define ENDL << endl;  // debug

const double PI {3.1415926535897932384626433832795};
const int MOD {static_cast<int>(1e9 + 7)};
const double EPS {1e-9};

// 1D-----------------------------------------------------
template<typename T, size_t N>  // array extraction
istream& operator>>(istream &is, array<T, N> &ARR) {
    for (T &a: ARR) is >> a;
    return is;
}

template<typename T, size_t N>  // array insertion
ostream& operator<<(ostream &os, array<T, N> &ARR) {
    for (T const &a: ARR) os << a << " ";
    return os;
}

template<typename T>  // vector extraction
istream& operator>>(istream &is, vector<T> &VEC) {
    for (T &v: VEC) is >> v;
    return is;
}

template <typename T>  // vector insertion
ostream& operator<<(ostream &os, const vector<T> &VEC) {
    for (T const &v: VEC) os << v << " ";
    return os;
}

template<typename T>  // deque extraction
istream& operator>>(istream &is, deque<T> &DEQ) {
    for (T &d: DEQ) is >> d;
    return is;
}

template<typename T>  // deque insertion
ostream& operator<<(ostream &os, const deque<T> &DEQ) {
    for (const T &d: DEQ) os << d << " ";
    return os;
}

template<typename T>  // list extraction
istream& operator>>(istream &is, list<T> &LIS) {
    for (T &l: LIS) is >> l;
    return is;
}

template<typename T>  // list insertion
ostream& operator<<(ostream &os, const list<T> &LIS) {
    for (T const &l: LIS) os << l << " ";
    return os;
}

template<typename T>  // set insertion
ostream& operator<<(ostream &os, const set<T> &ST) {
    for (auto const &s: ST) os << s << " ";
    return os;
}

template<typename T>  // unordered_set insertion
ostream& operator<<(ostream &os, const unordered_set<T> &U_ST) {
    for (T const &us: U_ST) os << us << " ";
    return os;
}

template<typename T1, typename T2>  // pair extraction
istream& operator>>(istream &is, pair<T1, T2> &PR) {
    is >> PR.first >> PR.second;
    return is;
}

template<typename T1, typename T2>  // pair debug
ostream& operator<<(ostream &os, const pair<T1, T2> &PR) {
    os << "[" << PR.first << ": " << PR.second << "]";
    return os;
}

template<typename T1, typename T2>  // map debug
ostream& operator<<(ostream &os, const map<T1, T2> &MP) {
    os << "[ ";
    for (pair<T1, T2> const &m: MP) os << m << " ";
    os << "]";
    return os;
}

template<typename T1, typename T2>  // unordered_map debug
ostream& operator<<(ostream& os, const unordered_map<T1, T2> &U_MP) {
    os << "[ ";
    for (pair<T1, T2> const &um: U_MP) os << um << " ";
    os << "]";
    return os;
}

template<typename T>  // stack debug
ostream& operator<<(ostream &os, stack<T> STACK) {
    while (!STACK.empty()) {
        os << STACK.top() << " ";
        STACK.pop();
    }
    return os;
}

template<typename T>  // queue debug
ostream& operator<<(ostream &os, queue<T> QUEUE) {
    while (!QUEUE.empty()) {
        os << QUEUE.front() << " ";
        QUEUE.pop();
    }
    return os;
}

// 2D----------------------------------------------------------------

template<typename T, size_t R, size_t C>  // 2D array insertion
ostream& operator<<(ostream &os, array<array<T, C>, R> &MAT) {
    for (array<T, C> &ROW: MAT) os << ROW << endl;
    return os;
}

template<typename T>  // 2D vector insertion
ostream& operator<<(ostream &os, vector<vector<T>> &MAT) {
    for (vector<T> &ROW: MAT) os << ROW << endl;
    return os;
}

template<typename T>
T max(const T &A, const T &B, const T &C) {
    T mx {A};
    (mx < B) && (mx = B);
    (mx < C) && (mx = C);
    return mx;
}

template<typename T>
T min(const T &A, const T &B, const T &C) {
    T mn {A};
    (mn > B) && (mn = B);
    (mn > C) && (mn = C);
    return mn;
}

template<typename T>
int cntDigits(const T &N) { return (static_cast<int>(log10(N)) + 1); }

template<typename T>
bool isPowOfTwo(const T &N) { return (N && (!(N&(N-1)))); }

template<typename T>
bool dblEqual(const T &a, const T &b) { return abs(a - b) < EPS; }

/* -------------------------------------------------------- */
/* -------------------------------------------------------- */

//

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cerr.setf(std::ios::boolalpha);
    cout << std::fixed;
    cout << std::setprecision(6); // default
    /* ---------------------------------- */

    ll n {};
    cin >> n;

    vector<ll> arr (n);
    for (auto &val: arr)
        cin >> val;

    ll ttl {};
    for (ll i {}; i < n; ++i)
        ttl = ((ttl%MOD) + (arr.at(i)%MOD))%MOD;

    ll ans {};
    for (ll i {}; i < n; ++i) {
        ttl = (((ttl%MOD) - (arr.at(i)%MOD))+MOD)%MOD;
        ans = ((ans%MOD)%MOD + ((ttl%MOD)*(arr.at(i)%MOD))%MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}
