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
    ll A, B, C, X, Y;

    void input() {
        cin >> A >> B >> C >> X >> Y;

    }

    void solve() {
        input();
        if (A > B) {
            swap(A, B);
            swap(X, Y);
        }

        // A <= B
        ll ans = 0ll;
        if (A + B >= 2 * C) {
            ll dec = min(X, Y);
            ll cost = 2 * C * dec;
            ans += cost;
            X -= dec;
            Y -= dec;
        }

        //A,Xの処理
        if (X > 0) {
            if (2 * C > A) {
                ll dec = X;
                ll cost = A * dec;
                ans += cost;
                X -= dec;
            } else {
                ll dec = X;
                ll cost = 2 * C * dec;
                ans += cost;
                X -= dec;
                Y -= dec;
            }
        }

        if (Y > 0) {
            if (2 * C > B) {
                ll dec = Y;
                ll cost = B * dec;
                ans += cost;
                Y -= dec;
            } else {
                ll dec = Y;
                ll cost = 2 * C * dec;
                ans += cost;
                X -= dec;
                Y -= dec;
            }
        }

        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}
