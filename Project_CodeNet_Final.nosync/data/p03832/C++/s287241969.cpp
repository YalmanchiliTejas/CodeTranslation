#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const int INF = 1001001001;
const ll mod = 1e+9 + 7;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

ll mod_pow(ll x, int n){
    if(n == 0)      return 1;

    ll res = 1;
    while(n > 0){
        if(n & 1)   res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

struct Combination{
    int sz;
    vector<ll> fact;
    vector<ll> ifact;

    Combination(int sz = 1e+5) : sz(sz) {
        fact = vector<ll>(sz + 1);
        ifact = vector<ll>(sz + 1);

        fact[0] = 1;
        for(ll i = 1; i <= sz; ++i){
            fact[i] = fact[i - 1] * i % mod;
        }

        ifact[sz] = mod_pow(fact[sz], mod - 2);
        for(ll i = sz; i > 0; --i){
            ifact[i - 1] = ifact[i] * i % mod;
        }
    }

    ll get_combination(int n, int r){
        if(n < 0 || r < 0 || n < r)     return 0;

        return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
    }
};

// product[i][j] := i 人グループを j 個作る場合の数
ll product[1005][1005];

ll dp[1005][1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    Combination comb(2 * 1e+6);
    for(int i = 0; i <= b; ++i) product[i][0] = 1;
    for(int i = 0; i <= b; ++i){
        for(int j = 1; j <= d; ++j){
            product[i][j] = product[i][j - 1] * comb.get_combination(i * j, i) % mod;
        }
        for(int j = 0; j <= d; ++j){
            product[i][j] *= comb.ifact[j];
            product[i][j] %= mod;
        }
    }
    dp[a-1][0] = 1;
    for(int i = a; i <= b; ++i){
        for(int j = 0; j <= n; ++j){
            chadd(dp[i][j], dp[i-1][j]);
            for(int k = c; k <= min(d, j / i); ++k){
                ll hoge = dp[i - 1][j - i * k] * comb.get_combination(n - (j - i * k), i * k) % mod;
                hoge = hoge * product[i][k] % mod;
                chadd(dp[i][j], hoge);
            }
        }
    }
    cout << dp[b][n] << "\n";
}