#pragma GCC optimize("O3") //コンパイラ最適化用

#define _GLIBCXX_DEBUG //配列に[]でアクセス時のエラー表示
#include <algorithm>   //sort,二分探索,など
#include <bitset>      //固定長bit集合
#include <cassert>     //assert(p)で，not pのときにエラー
#include <cctype>
#include <chrono>  //実行時間計測
#include <cmath>   //pow,logなど
#include <complex> //複素数
#include <cstring>
#include <deque>
#include <functional> //sortのgreater
#include <iomanip>    //setprecision(浮動小数点の出力の誤差)
#include <ios>        // std::left, std::right
#include <iostream>   //入出力
#include <iterator>   //集合演算(積集合,和集合,差集合など)
#include <map>
#include <numeric> //iota(整数列の生成),gcdとlcm,accumulate
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility> //pair
#include <vector>  //可変長配列
using namespace std;
typedef long long LL;
typedef long double LD;

#define ALL(x) x.begin(), x.end()
#define SIZE(x) LL(x.size()) // sizeをsize_tからLLに直しておく
const long long INF = 1e12;
const int MOD = 1e9 + 7;
#define MAXR 100000 // 10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define UMAP unordered_map
#define USET unordered_set
#define FF first
#define SS second
#define int long long
#define LD long double
#define PII pair<int, int>
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define VVI vector<vector<int>>
#define VLL vector<LL>
#define VVLL vector<vector<LL>>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(b)-1; i >= (int)a; i--)

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1},
          Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

// https://qiita.com/Lily0727K/items/06cb1d6da8a436369eed#c%E3%81%A7%E3%81%AE%E5%AE%9F%E8%A3%85
void print() { cout << "\n"; }

template <class Head, class... Tail> void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail) != 0)
        cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T> void print(vector<T> &vec) {
    for (auto &a : vec) {
        cout << a;
        if (&a != &vec.back())
            cout << " ";
    }
    cout << "\n";
}

template <class T> void print(vector<vector<T>> &df) {
    for (auto &vec : df) {
        print(vec);
    }
}
long long power(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a *= a;
        n >>= 1;
    }
    return res;
}
long long comb(int n, int k) {
    vector<vector<long long>> v(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int k = 1; k < v.size(); k++) {
        for (int j = 1; j < k; j++) {
            v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
        }
    }
    return v[n][k];
}
void add(long long &a, long long b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

__attribute__((constructor)) void faster_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// modint: mod 計算を int を扱うように扱える構造体
// https://github.com/drken1215/algorithm/blob/master/MathCombinatorics/mod.cpp
// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a

template <int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator-() const noexcept { return val ? MOD - val : 0; }
    constexpr Fp operator+(const Fp &r) const noexcept {
        return Fp(*this) += r;
    }
    constexpr Fp operator-(const Fp &r) const noexcept {
        return Fp(*this) -= r;
    }
    constexpr Fp operator*(const Fp &r) const noexcept {
        return Fp(*this) *= r;
    }
    constexpr Fp operator/(const Fp &r) const noexcept {
        return Fp(*this) /= r;
    }
    constexpr Fp &operator+=(const Fp &r) noexcept {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr bool operator==(const Fp &r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os,
                                         const Fp<MOD> &x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};

// 二項係数ライブラリ
template <class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int MOD = fact_[0].getmod();
        for (int i = 2; i < n; i++) {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = -inv_[MOD % i] * (MOD / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0)
            return 0;
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0)
            return 0;
        return fact_[n];
    }
    // 追加
    constexpr T perm(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0)
            return 0;
        return fact_[n] * finv_[k] * finv_[n - k] * fact_[k];
    }

    constexpr T inv(int n) const noexcept {
        if (n < 0)
            return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0)
            return 0;
        return finv_[n];
    }
};

using mint = Fp<MOD>;
BiCoef<mint> bc;
/*
int main() {
    long long N, M, K; cin >> N >> M >> K;
    bc.init(510000); // 忘れない！
    mint sum = 0;
    for (int i = 0; i <= N-1; ++i) {
        for (int j = 0; j <= M-1; ++j) {
            mint tmp = mint(N - i) * mint(M - j) * mint(i + j);
            modpow(mint(i),N); // 引数はllあるいはmintにして渡す
            if (i != 0 && j != 0) tmp *= 2;
            sum += tmp;
        }
    }
    cout << sum * bc.com(N*M-2, K-2) << endl;
}
*/
mint findProductSum(VI A, int n) {
    // calculating array sum (a1 + a2  ... + an)
    mint array_sum = 0;
    for (int i = 0; i < n; i++)
        array_sum = array_sum + A[i];

    // calcualting square of array sum
    // (a1 + a2 + ... + an)^2
    mint array_sum_square = array_sum * array_sum;

    // calcualting a1^2 + a2^2 + ... + an^2
    mint individual_square_sum = 0;
    for (int i = 0; i < n; i++)
        individual_square_sum += A[i] * A[i];

    // required sum is (array_sum_square -
    // individual_square_sum) / 2
    return mint(array_sum_square - individual_square_sum) / 2;
}

// Driver code
int n;
signed main() {
    cin >> n;
    VI A(n);
    REP(ni, n) { cin >> A[ni]; }

    print(findProductSum(A, n));
    return 0;
}
