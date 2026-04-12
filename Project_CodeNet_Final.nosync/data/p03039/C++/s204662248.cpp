#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
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
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, ll> Pl;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const int mod = 1e+9 + 7;
const int INF = 1e+9;

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    if(n < m)   swap(n, m);
    Combination c(n * m);
    ll mul = c.get_combination(n * m - 2, k - 2);
    ll res = 0;
    ll add = 0;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            for(int i = y; i >= 0; --i){
                // 初項 : y-i+1, 公差 : 1, 要素数 : n-(x+1) の等差数列の和
                add = (n - (x+1)) * (y - i + 1) + (n - (x+1)) * (n - (x+1) - 1) / 2;
                res = (res + add) % mod;
                // cerr << "(" << x << ", " << y << ") " << i << "  " << add << "\n";
            }
            for(int i = y+1; i < m; ++i){
                // 初項 : i-y, 公差 : 1, 要素数 : n-x の等差数列の和
                add = (n - x) * (i - y) + (n - x) * (n - x - 1) / 2;
                res = (res + add) % mod;
                // cerr << "(" << x << ", " << y << ") " << i << "  " << add << "\n";
            }
        }
    }
    res = res * mul % mod;
    cout << res << endl;
}