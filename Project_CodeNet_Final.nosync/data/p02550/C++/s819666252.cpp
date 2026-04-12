#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <utility>
#include <functional>
#include <map>
#include <set>
#include <cctype>
#include <fstream>
#include <numeric>
#include <cassert>

#include <cstdint>
#include <iomanip>
#include <cstring>
using namespace std;
using ll = long long;
#define ALL(a) (a).begin(), (a).end()

#define FOR(i, a, b) for (long long int i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (long long int i = (a); i >= (b); i--)

const int MOD = 998244353;

#define LLONG_MAXs 9223372036854775800 / 2
//#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
#define ALL(a) (a).begin(), (a).end()

#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNum(ll x)
{ // 素数である場合 true を返す
    if (x <= 1)
    { // 1以下である場合は素数でないことがすぐにわかる
        return false;
    }
    // sqrt( double型 ) は引数の平方根を double型で返すので、int型でキャスト
    int n = (int)sqrt((double)x);
    for (int i = 2; i <= n; i++)
    {
        if (x % i == 0)
        { // 割り切る整数がある場合、即判定終了
            return false;
        }
    }
    return true; // 割り切る整数がない場合、素数である
}

ll myPow(ll x, ll n, ll m)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return myPow(x * x % m, n / 2, m);
    else
        return x * myPow(x, n - 1, m) % m;
}

constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
constexpr ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
constexpr ll abs(ll a, ll b)
{
    if (a >= b)
        return a - b;
    if (a < b)
        return b - a;
}
constexpr double dabs(double a, double b)
{
    if (a >= b)
        return a - b;
    if (a < b)
        return b - a;
}
constexpr ll min(ll a, ll b)
{
    if (a >= b)
        return b;
    if (a < b)
        return a;
}

constexpr ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    if (a < b)
        return b;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dx8[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy8[8] = {0, 1, 0, -1, 1, 1, -1, -1};

class UnionFind
{
public:
    //親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> Parent;

    //作るときはParentの値を全て-1にする
    //こうすると全てバラバラになる
    UnionFind(int N)
    {
        Parent = vector<int>(N, -1);
    }

    //Aがどのグループに属しているか調べる
    int root(int A)
    {
        if (Parent[A] < 0)
            return A;
        return Parent[A] = root(Parent[A]);
    }

    //自分のいるグループの頂点数を調べる
    int size(int A)
    {
        return -Parent[root(A)]; //親をとってきたい]
    }
    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }
    //AとBをくっ付ける
    bool connect(int A, int B)
    {
        //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B)
        {
            //すでにくっついてるからくっ付けない
            return false;
        }

        //大きい方(A)に小さいほう(B)をくっ付けたい
        //大小が逆だったらひっくり返しちゃう。
        if (size(A) < size(B))
            swap(A, B);

        //Aのサイズを更新する
        Parent[A] += Parent[B];
        //Bの親をAに変更する
        Parent[B] = A;

        return true;
    }
};

long long fac[510000], finv[510000], inv[510000];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 510000; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

void yn(bool flag)
{
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return;
}
void YN(bool flag)
{
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}

std::vector<ll> enum_div(ll n) //nの約数を列挙
{
    std::vector<ll> ret;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i != 1 && i * i != n)
            {
                ret.push_back(n / i);
            }
        }
    }
    ret.push_back(n);
    return ret;
}

// modint: mod 計算を int を扱うように扱える構造体
template <int MOD>
struct Fp
{
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator-() const noexcept
    {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator+(const Fp &r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator-(const Fp &r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator*(const Fp &r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator/(const Fp &r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp &operator+=(const Fp &r) noexcept
    {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept
    {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept
    {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept
    {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b)
        {
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
    constexpr bool operator==(const Fp &r) const noexcept
    {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept
    {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept
    {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept
    {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};

using mint = Fp<MOD>;

// グラフセット
struct Edge
{
    ll to;     // 辺の行き先
    ll weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) {}
};

typedef vector<vector<long long>> matrix;
matrix mul_mod(matrix A, matrix B)
{
    int H = A.size();
    int W = B[0].size();
    int K = A[0].size();

    matrix C(H, vector<ll>(W, 0));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            for (int k = 0; k < K; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

// 区間加算にも対応した BIT
template <class Abel>
struct BIT
{
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0; // to be set

    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n)
    {
        for (int iter = 0; iter < 2; ++iter)
            dat[iter].assign(n + 1, UNITY_SUM);
    }

    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x)
    {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x)
    {
        sub_add(0, a, x * -(a - 1));
        sub_add(1, a, x);
        sub_add(0, b, x * (b - 1));
        sub_add(1, b, x * (-1));
    }

    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a)
    {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b)
    {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }

    /* debug */
    void print()
    {
        for (int i = 1; i < (int)dat[0].size(); ++i)
            cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};
//cout << std::setprecision(30) << ans << endl;

using Graph = vector<vector<ll>>;

void print(const std::vector<int> &v)
{
    std::for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}
const double PI = 3.14159265358979323846;
ll times_cap(ll a, ll b)
{
    if (log10(a) + log10(b) >= 19.0)
        return -1;
    else
        return a * b;
}
//cout<<std::setprecision(30)
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Segment Tree
template <class Monoid, class Action>
struct SegTree
{
    using FuncMonoid = function<Monoid(Monoid, Monoid)>;
    using FuncAction = function<void(Monoid &, Action)>;
    using FuncLazy = function<void(Action &, Action)>;
    FuncMonoid FM;
    FuncAction FA;
    FuncLazy FL;
    Monoid UNITY_MONOID;
    Action UNITY_LAZY;
    int SIZE, HEIGHT;
    vector<Monoid> dat;
    vector<Action> lazy;

    SegTree() {}
    SegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy)
        : FM(fm), FA(fa), FL(fl), UNITY_MONOID(unity_monoid), UNITY_LAZY(unity_lazy)
    {
        SIZE = 1;
        HEIGHT = 0;
        while (SIZE < n)
            SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }
    void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
              const Monoid &unity_monoid, const Action &unity_lazy)
    {
        FM = fm;
        FA = fa;
        FL = fl;
        UNITY_MONOID = unity_monoid;
        UNITY_LAZY = unity_lazy;
        SIZE = 1;
        HEIGHT = 0;
        while (SIZE < n)
            SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }

    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE] = v; }
    void build()
    {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
    }

    /* update [a, b) */
    inline void evaluate(int k)
    {
        if (lazy[k] == UNITY_LAZY)
            return;
        if (k < SIZE)
            FL(lazy[k * 2], lazy[k]), FL(lazy[k * 2 + 1], lazy[k]);
        FA(dat[k], lazy[k]);
        lazy[k] = UNITY_LAZY;
    }
    inline void update(int a, int b, const Action &v, int k, int l, int r)
    {
        evaluate(k);
        if (a <= l && r <= b)
            FL(lazy[k], v), evaluate(k);
        else if (a < r && l < b)
        {
            update(a, b, v, k * 2, l, (l + r) >> 1), update(a, b, v, k * 2 + 1, (l + r) >> 1, r);
            dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
        }
    }
    inline void update(int a, int b, const Action &v) { update(a, b, v, 1, 0, SIZE); }

    /* get [a, b) */
    inline Monoid get(int a, int b, int k, int l, int r)
    {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return FM(get(a, b, k * 2, l, (l + r) >> 1), get(a, b, k * 2 + 1, (l + r) >> 1, r));
        else
            return UNITY_MONOID;
    }
    inline Monoid get(int a, int b) { return get(a, b, 1, 0, SIZE); }
    inline Monoid operator[](int a) { return get(a, a + 1); }

    /* debug */
    void print()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            cout << (*this)[i];
            if (i != SIZE)
                cout << ",";
        }
        cout << endl;
    }
};

int main()
{
    ll N, X, M;
    ll ans = 0;
    cin >> N >> X >> M;
    map<ll, ll> mp;
    ans += X;
    ll now = X;
    mp[now]++;
    ll lp = 0;
    ll lps = 0;
    ll saisyo = 1;
    ll lpstart = -1;
    FOR(i, 1, min(N - 1, M * 10))
    {
        now = now * now;
        now %= M;
        if (mp.count(now) == 0)
        {
            ans += now;
            saisyo++;
        }
        else
        {
            if (mp[now] == 1)
            {
                if (lpstart == -1)
                {
                    lpstart = now;
                }
                lp++;
                lps += now;
            }
        }
        mp[now]++;
    }
    //cout << lp << " " << lps << " " << lpstart << endl;

    ll nokori = N - saisyo;
    if (nokori > 1)
    {
        ans += (nokori / lp) * lps;
        nokori %= lp;
        //cout << nokori << endl;
        now = lpstart;
        FOR(i, 1, nokori)
        {
            ans += now;
            now = now * now;
            now %= M;
        }
    }

    cout << ans << endl;
    return 0;
}