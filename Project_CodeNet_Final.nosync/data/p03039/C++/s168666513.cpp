#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;

const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

ll n, m, k;

// modを維持しながらべき乗。
ll mod_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

// 逆元。オイラーの定理から？
// 有限体上での割り算に利用
// 3/4 = 3*(1/4) = 3x(4の逆数) = 3x3 mod 11
// 4の逆数はかけると1になるので、この場合は3
ll mod_inverse(ll x) {
    return mod_pow(x, mod-2);
}

const int max_n = 1000000;
ll fact[max_n];
ll fact_inv[max_n];

void calc_fact() {
    fact[0] = 1;
    //階乗の算出。かける度にmodを取る。
    for (ll i = 1; i < max_n; i++)
        fact[i] = (fact[i-1] * i) % mod;
    //階乗の逆元の算出。
    //1*2*3 => 1/(1*2*3)
    //1*2 => 1/(1*2*3)*3
    fact_inv[max_n-1] = mod_inverse(fact[max_n-1]);
    for (ll i = max_n-2; i >= 0; i--) 
        fact_inv[i] = (fact_inv[i+1] * (i+1)) % mod;
}

//mod付き組み合わせ
// nCk= n!/(n-k)!k! を、modをかませながら演算
ll mod_comb(ll n, ll k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return (fact[n] * fact_inv[k] % mod) * fact_inv[n-k] % mod;
}

//本編
//X方向,y方向に分割して計算
ll solve() {
    ll b = 0;
    // まずは列を横断
    // 興味があるのは、違う列にあるものだけ。
    // m-i: m列ある中でi列離れているときの、組み合わせの数
    // n*n: 2つの列の、行の組み合わせの数
    // i: Xの差の絶対値(2コマのX方向の距離)
    // m: 1,2,3,4の時
    // n: 1,2,3,4の時
    // n*n: 行1~4から2つ選ぶ
    // m-i: iが1の時1-2, 2-3, 3-4の3つ。
    for (int i = 1; i < m; i++) {
    	//行の位置(2コマ) * 列の組み合わせ + 距離スコア
        b += n * n * (m-i) * i;
        b %= mod;
    }
    for (int i = 1; i < n; i++) {
        b += m * m * (n-i) * i;
        b %= mod;
    }

    calc_fact();
    // 最初に2つを固定してそのほかの組み合わせ数Cをかける。
    // コマ1,2の距離はb。ほかのコマの組み合わせがどうであれ、bは変わらない。となるとb*Cで、コマ1,2についての距離の総和が求まる
    return b * mod_comb(n*m-2, k-2) % mod;
}

void input() {
    cin >> n >> m >> k;
}

int main() {
    input();
    cout << solve() << endl;
}
