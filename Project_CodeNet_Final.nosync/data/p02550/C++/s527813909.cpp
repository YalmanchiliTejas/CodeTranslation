#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
// #include <atcoder/all>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x, m; cin >> n >> x >> m;
    if (n <= 10000000) {
        ll ans = x;
        for (ll i = 1; i < n; i++) {
            x = x * x % m;
            ans += x;
        }
        cout << ans << '\n';
    } else {
        ll start, sx;
        V<int> used(m + 1, -1);
        used[x] = 0;
        ll origx = x;
        for (int i = 1; ;i++) {
            x = x * x % m;
            if (used[x] > -1) {
                start = used[x];
                sx = x;
                break;
            } else used[x] = i;
        }
        n -= start;

        ll ans = (start == 0 ? 0 : origx);
        x = origx;
        for (int i = 1; i < start; i++) {
            x = x * x % m;
            ans += x;
        }

        vll loop;
        ll loopsum = 0;
        x = sx;
        do {
            loopsum += x;
            loop.emplace_back(x);
            x = x * x % m;
        } while (x != sx);

        ans += n / ll(loop.size()) * loopsum;
        n -= n / ll(loop.size()) * ll(loop.size());
        for (ll i = 0; i < n; i++) {
            ans += sx;
            sx = sx * sx % m;
        }
        cout << ans << '\n';
    }
    return 0;
}
