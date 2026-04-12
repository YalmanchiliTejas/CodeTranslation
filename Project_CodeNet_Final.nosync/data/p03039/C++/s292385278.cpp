#pragma region includes, macros
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <limits>

using namespace std;

typedef int64_t i64;
typedef pair<i64, i64> P;

static const i64 MOD = 1000000007;

//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge {
    i64 from, to, cost;
    edge(i64 to, i64 cost) : from(-1), to(to), cost(cost) {}
    edge(i64 src, i64 to, i64 cost) : from(src), to(to), cost(cost) {}
};

// http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e : t) fill_v(e, v);
}
//

#pragma endregion

int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };

const i64 MAX = 510000;

i64 fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
i64 COM(i64 n, i64 k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

i64 s(i64 x) {
    return (x * (x + 1) / 2) % MOD;
}

i64 extGCD(i64 a, i64 b, i64& x, i64& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 d = extGCD(b, a % b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline i64 mod(i64 a, i64 m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
i64 modinv(i64 a, i64 m) {
    i64 x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}

int main() {
    i64 n, m, k;
    cin >> n >> m >> k;
    COMinit();
    i64 ans = 0, cnt = 1;
    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < m; ++j) {
            i64 x = (((s(m - j - 1) + s(j)) % MOD * n) % MOD);
            i64 y = (((s(n - i - 1) + s(i)) % MOD * m) % MOD);
            i64 z = (COM(n * m - 2, k - 2) * (x + y)) % MOD;
            ans = (ans + z) % MOD;
        }
    }
    cout << (ans * modinv(2, MOD)) % MOD << endl;
}

// (1, 1) (1 + 2 + .. m - 1) * n + (1 + 2 ... + n - 1) * m * (n * m - 1)C(k - 1)
// (0 + 1 + 1 + 2
