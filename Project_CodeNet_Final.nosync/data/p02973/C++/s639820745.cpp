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

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << '\n';
#define SAY(X) cout << (X) << '\n';
#else
#define DBG(X)
#define SAY(X)
#endif

#define M_PI       3.14159265358979323846

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

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

ll solve()
{
    int n;

    cin >> n;

    vector<int> nums = fetch_vec<int>(n);
    map<int, int> tails;

    for (int i = 0; i < n; ++i)
    {
        tails[nums[i]]++;

        auto it = tails.find(nums[i]);
        if (it != tails.begin())
        {
            --it;
            it->second--;
            if (it->second == 0)
                tails.erase(it);
        }
    }

    int counter = 0;
    for (auto& it: tails)
        counter += it.second;

    cout << counter << endl;

    return 0;
}

int main()
{
    solve();

    return 0;
}
