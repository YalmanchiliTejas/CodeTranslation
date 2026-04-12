#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << '\n';
#define SAY(X) cout << (X) << '\n';
#else
#define DBG(X)
#define SAY(X)
#endif

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

std::string pad(int num)
{
    char buffer[4];
    std::snprintf(buffer, sizeof(buffer), "%03d", num);
    return buffer;
}

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

struct Hashing {
    ull seed, mod;
    vector <ull> hs, pw;

    Hashing(ull seed = 31, ull mod = 1000173169) :
        seed(seed),
        mod(mod) {}

    void build(int n, const string& s) {
        hs.assign(n + 1, 0);
        pw.assign(n + 1, 1);
        pw[0] = 1;

        for (int i = 1; i <= n; ++i)
            pw[i] = pw[i - 1] * seed % mod;
        for (int i = 1; i <= n; ++i)
            hs[i] = (hs[i - 1] * seed + s[i]) % mod;
    }

    ull hash(int l, int r) {
        return (hs[r] - hs[l - 1] * pw[r - l + 1] % mod + mod) % mod;
    }
};

int solve()
{
    int n, m;

    std::cin >> n >> m;

    if (m >= n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

int main()
{
//    std::cout << solve() << std::endl;
    solve();

    return 0;
}