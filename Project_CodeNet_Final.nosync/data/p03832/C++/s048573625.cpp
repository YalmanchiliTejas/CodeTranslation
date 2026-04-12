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
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 20)
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

    ll nPk(int n, int k) {
        return (((fact[n] * pow(fact[n - k], MOD - 2)) % MOD)) % MOD;
    }

    ll extgcd(ll a, ll b, ll &x, ll &y) {
        ll d = a;
        if (b != 0) {
            d = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
        } else {
            x = 1;
            y = 0;
        }
        return d;
    }

    ll mod_inverse(ll a, ll m) {
        ll x, y;
        extgcd(a, m, x, y);
        return (m + x % m) % m;
    }
};

Combination comb(1001);
ll npk[1001][1001] = {};
ll mi[1001] = {};
ll pmi[1001][1001] = {};
ll func(int n, int x, int k) {
    ll ret;
    if(npk[n][x*k] == -1){
        ret = npk[n][x*k] = comb.nPk(n, x * k);
    }else{
        ret = npk[n][x*k];
    }
    if(mi[x] == -1){
        mi[x] = comb.mod_inverse(comb.fact[x], MOD);
    }
    ret *= mi[x];
    ret %= MOD;
    if(pmi[k][x] == -1){
        pmi[k][x] = comb.pow(comb.mod_inverse(comb.fact[k], MOD), x);
    }
    ret *= pmi[k][x];
    ret %= MOD;
    return ret;
}

int A, B, C, D;
ll memo[1001][1001] = {};

ll dfs(int n, int k) {
    ll ret = 0;
    if (n == 0) return memo[n][k] = 1;
    if (k == 0) return memo[n][k] = 0;
    if (memo[n][k] != -1) return memo[n][k];
    ret += dfs(n, k - 1);
    ret %= MOD;
    if (k >= A && k <= B) {
        for (int x = C; x <= D; x++) {
            if (n - x * k >= 0) {
                ret += dfs(n - x * k, k - 1) * func(n, x, k) % MOD;
                ret %= MOD;
            } else break;
        }
    }
    return memo[n][k] = ret;

}

int main() {
    int N;
    rep(i, 0, 1001) {
        rep(j, 0, 1001) {
            memo[i][j] = -1;
            npk[i][j] = -1;
            pmi[i][j] = -1;
        }
        mi[i] = -1;
    }

    cin >> N >> A >> B >> C >> D;
    cout << dfs(N, N) << endl;
    return 0;
}
