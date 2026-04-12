#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>


using namespace std;

typedef long long ll;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<ll> vll;

typedef vector<vector<ll>> vvll;

typedef pair<int, int> P;
#define mp(x, y) make_pair(x, y)

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define repm(i, n) for(int i=n; i >= 0; i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える

//nが素数かをO(√n)で判断
bool is_prime(int n) {
    bool res = true;

    if (n == 1) return false;
    else if (n == 2) return true;

    else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                res = false;
                break;
            }
        }
    }

    return res;
}

//「ソートされた」(ここ大事)vectorに対して二分探索を行う
int BinarySearch(vector<int> vec, int key) {
    int left = 0; int right = vec.size();

    while (left < right) {
        int mid = (left + right) / 2;

        if (vec[mid] == key) return mid;
        else if (mid < key) left = mid - 1;
        else right = mid + 1;
    }

    return -1;
}

//C(x)
bool C(int x) {
    bool res = false;
    return res;
}



//めぐる式二分探索
ll Binary_search() {
    //絶対にオッケーな値、初期値。
    ll ok = 1e10;
    //絶対にNGな値、初期値。
    ll ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (C(mid)) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }
    return ok;
}

int perm(int n, int r) {
    if (r == 1) return n;
    return n * perm(n - 1, r - 1);
}

int fact(int n) {
    if (n == 1) return 1;
    return fact(n - 1) * n;
}

int comb(int n, int r) {
    int a = min(n, r), b = max(n, r);
    return perm(a, b) / fact(a);
}



/*
ll pow_mod(ll a, ll n, ll mod) {
    ll res = 1;

    ll base = a;
    while (n) {
        if (n & 1) res = res * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return res;
}
*/

//aの逆元　（a^(-1)）を求める
ll inv_mod(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

/*
ll fact_mod(ll n, ll mod) {
    if (n == 1) return 1;
    return n * fact_mod(n - 1, mod) * mod;
}
*/

// 階乗 (mod とりバージョン)
ll fact_mod(ll n, ll mod) {
    ll f = 1; for (int i = 2; i <= n; i++) f = f * (i % mod) % mod;
    return f;
}

// 繰り返し二乗法 (modの世界での累乗)
// ※modが素数の場合、この関数で(mod - 2)乗したら、mod割り算ができるよ！
// (参考問題: ABC034 C問題など)
ll pow_mod(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % mod; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % mod;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}

// 組み合わせ nCr を求める (modあり)
ll comb_mod(ll n, ll r, ll mod) {
    if (r > n - r) r = n - r;
    if (r == 0) return 1;
    ll a = 1;
    for (int i = 0; i < r; i++) a = a * ((n - i) % mod) % mod;
    ll b = pow_mod(fact_mod(r, mod), mod - 2, mod);
    return (a % mod) * (b % mod) % mod;
}

const ll mod = 100000;
//mod := pow(10, 9) + 7


int main() {
    int x; cin >> x;
    if (x >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
}