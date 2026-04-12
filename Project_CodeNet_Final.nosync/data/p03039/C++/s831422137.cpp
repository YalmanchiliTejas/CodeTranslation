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

//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Combination {

public:
    vector<ll> fact;

    Combination(int max_n) {
        //1 ~ n!までの階乗modを求める
        int n = max_n;
        vector<ll> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        this->fact = fact;
    }

    template<typename T>
    //templateをつかってみｔか
    ll pow(T x, int y) {
        if (y == 0) return 1;
        if (y == 1) return x;
        if (y == 2) return (x * x) % MOD;
//        if (y % 2 == 1) return pow(x, y / 2) * pow(x, y / 2) % MOD;
        if (y % 2 == 1) return pow(pow(x, y / 2), 2) * x % MOD;
//        return pow(x, y / 2) * pow(x, y / 2) % MOD;
        return pow(pow(x, y / 2), 2) % MOD;
    }

    ll nCk(int n, int k) {
//        return (fact[n] * pow(fact[n-k],MOD-2) * pow(fact[k],MOD-2)) % MOD;
        return (((fact[n] * pow(fact[n - k], MOD - 2)) % MOD) * pow(fact[k], MOD - 2)) % MOD;
    }

    /**
     * x ^ -1を求める
     */
    template<typename T>
    ll inv(T x) {
        return pow(x, MOD - 2);
    }
};

class Solve {
public:
    void input() {

    }

    void solve() {
        input();
        ll N, M, K;
        cin >> N >> M >> K;
        Combination cmb(N * M);
        ll ans = 0ll;
        for (int d = 1; d <= M; ++d) {
            ll tmp = d * (M - d);
            tmp %= MOD;
            tmp *= N;
            tmp %= MOD;
            tmp *= N;
            tmp %= MOD;
//            tmp *= cmb.nCk(N * M - 2, K - 2);
            ans += tmp;
            ans %= MOD;

        }

        for (int d = 1; d <= N; ++d) {
            ll tmp = d * (N - d);
            tmp %= MOD;
            tmp *= M;
            tmp %= MOD;
            tmp *= M;
            tmp %= MOD;
//            tmp *= cmb.nCk(N * M - 2, K - 2);
            ans += tmp;
            ans %= MOD;
        }

        ans *= cmb.nCk(N * M - 2, K - 2);
        ans %= MOD;


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
