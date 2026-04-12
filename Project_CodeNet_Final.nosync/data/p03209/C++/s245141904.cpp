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
    vector<ll> s;
    vector<ll> p;

    void input() {
        s.resize(60);
        p.resize(60);
        s[0] = 1ll;
        p[0] = 1ll;
        for (int i = 1; i <= 50; ++i) {
            s[i] = 3 + 2 * s[i - 1];
            p[i] = 1 + 2 * p[i - 1];
        }
    }

    ll f(ll X, int L) {
        if (L == 0) return 1;
        if (X == 1) return 0;
        if (2 * X < s[L] + 1) return f(X - 1, L - 1);
        if (2 * X == s[L] + 1) return p[L - 1] + 1;
        if (X < s[L]) return p[L - 1] + 1 + f(X - (2 + s[L - 1]), L - 1);
        if (X == s[L]) return p[L];
    }

    void solve() {
        input();
        int N;
        ll X;
        cin >> N >> X;

        ll ans = f(X, N);
        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}
