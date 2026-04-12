#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Solve {
public:
    int N;
    vector<ll> a;
    vector<vector<vector<ll> > > dp;

    void input() {
        cin >> N;
        a.resize(N);
        rep(i, 0, N) cin >> a[i];
        dp.resize(N, vector<vector<ll>>(N, vector<ll>(2, -1)));

    }

    ll rec(int s, int t, int u) {
        if (dp[s][t][u] != -1) return dp[s][t][u];

        if (s == t) {
            if (u == 0)
                return dp[s][t][u] = a[s];
            else
                return dp[s][t][u] = -a[s];
        }

        if (u == 0) {
            //最大化
            ll val1 = rec(s + 1, t, 1) + a[s];
            ll val2 = rec(s, t - 1, 1) + a[t];

            return dp[s][t][u] = max(val1, val2);
        } else {
            //最小化
            ll val1 = rec(s + 1, t, 0) - a[s];
            ll val2 = rec(s, t - 1, 0) - a[t];

            return dp[s][t][u] = min(val1, val2);
        }

    }

    void solve() {
        input();
        ll ans = rec(0, N - 1, 0);
        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}
