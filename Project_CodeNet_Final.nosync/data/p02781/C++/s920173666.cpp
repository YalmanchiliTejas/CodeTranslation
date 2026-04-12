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
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
class Solve {
public:
    string N;
    Int K;

    Int dp[101][2][11][4][101];

    Int rec(Int n = 0, Int t = 1, Int x = 0, Int k = 0, Int d = 0) {
        if (dp[n][t][x][k][d] != -1) {
            return dp[n][t][x][k][d];
        }
        if (n == N.size()) {
            return dp[n][t][x][k][d] = k == K;
        }

        int max_x = t ? (N[n] - '0') : 9;
        Int ret = 0;
        for (int nx = 0; nx <= max_x; ++nx) {
            Int tmp = 0;
            if (nx == 0) {
                tmp = rec(n + 1, nx == max_x && t, nx, k + (nx != 0), d);
            } else {
                if (k + (nx != 0) <= K) {
                    if (d == 0) {
                        tmp = rec(n + 1, nx == max_x && t, nx, k + (nx != 0), n);
                    } else {
                        tmp = rec(n + 1, nx == max_x && t, nx, k + (nx != 0), 0);
                    }
                }
            }
            ret += tmp;
        }

        return dp[n][t][x][k][d] = ret;
    }

    void solve() {
        memset(dp, -1, sizeof(dp));
        cin >> N >> K;

        Int ans = rec();
        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
