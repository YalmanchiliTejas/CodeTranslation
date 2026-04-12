#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define endl '\n'
#define loop(i, n) for (unsigned int i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define modd 1000000007ll
//#define modd 998244353ll
#define flagcount(bit) __builtin_popcount(bit)
#define flag(x) (1ll << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1ll << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << '\n'
#define Sum(v) accumulate(all(v), 0ll)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}
template <typename T>
string make_string(T N)
{
    string ret;
    T now = N;
    while (now > 0)
    {
        T x = now % 10;
        ret += (char)('0' + x);
        now /= 10;
    }
    reverse(all(ret));
    return ret;
}
template <typename T>
T gcd(T a, T b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));
/*
抽象化したセグメント木
ex)要素数n,long long型,区間最大クエリ(fx),点加算(gx)のセグメント木が欲しい場合
auto fx=[](long long x,long long y){return max(x,y);};
auto gx=[](long long a,long long b){return a+b;};
long long id=numeric_limits<long long>::lowest();//単位元 実際の実装では十分小さい値でよい
segment_tree<long long> tree(n,id,fx,gx);で宣言 要素は単位元で初期化される

gcdを区間に作用させるときは単位元を0にするらしい
gxを点更新とする場合にはgxを省略できる
以下宣言後できること一覧(0-indexedで考える)
build(A):長さnの配列Aで要素を初期化する
update(i,x):i番目の値をxを用いて更新させる(更新,加算など)
query(l,r):区間[l,r]に対してfxを作用させた結果を返す
tree[x],tree.at(x):x番目の値を取得する
*/
template <typename T>
struct segment_tree
{
private:
    using FX = function<T(T, T)>;
    int n;
    T id;
    vector<T> data;
    FX fx, gx; //区間操作, 点更新操作用
    //[a,b)に対する区間操作　kは[l,r)に対するデータを保持する
    T sub_query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return id;
        if (a <= l && r <= b)
            return data[k];
        T L = sub_query(a, b, 2 * k + 1, l, (l + r) / 2); //左の子
        T R = sub_query(a, b, 2 * k + 2, (l + r) / 2, r); //右の子
        return fx(L, R);
    }
    int sub_find_rightest_min(T x, int a, int b, int k, int l, int r)
    {
        if (data[k] > x || r <= a || b <= l)
            return a - 1;
        if (k >= n - 1)
            return k - (n - 1);
        int R = sub_find_rightest_min(x, a, b, 2 * k + 2, (l + r) / 2, r);
        if (R != a - 1)
            return R;
        return sub_find_rightest_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
    }
    int sub_find_leftest_min(T x, int a, int b, int k, int l, int r)
    {
        if (data[k] > x || r <= a || b <= l)
            return b;
        if (k >= n - 1)
            return k - (n - 1);
        int L = sub_find_leftest_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
        if (L != b)
            return L;
        return sub_find_leftest_min(x, a, b, 2 * k + 2, (l + r) / 2, r);
    }
    int sub_find_rightest_max(T x, int a, int b, int k, int l, int r)
    {
        if (data[k] < x || r <= a || b <= l)
            return a - 1;
        if (k >= n - 1)
            return k - (n - 1);
        int R = sub_find_rightest_max(x, a, b, 2 * k + 2, (l + r) / 2, r);
        if (R != a - 1)
            return R;
        return sub_find_rightest_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
    }
    int sub_find_leftest_max(T x, int a, int b, int k, int l, int r)
    {
        if (data[k] < x || r <= a || b <= l)
            return b;
        if (k >= n - 1)
            return k - (n - 1);
        int L = sub_find_leftest_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
        if (L != b)
            return L;
        return sub_find_leftest_max(x, a, b, 2 * k + 2, (l + r) / 2, r);
    }

public:
    segment_tree(int n0, T id0, FX fx0, FX gx0) : n(1), id(id0), fx(fx0), gx(gx0)
    {
        while (n < n0)
            n *= 2;
        data.resize(2 * n - 1, id); //単位元で初期化
    }
    //1点更新クエリの場合はgxを省略できるように
    segment_tree(int n0, T id0, FX fx0) : segment_tree(n0, id0, fx0, [](T a, T b) { return b; }) {}
    //配列Aの値で初期化する
    void build(vector<T> A)
    {
        T siz = A.size();
        for (int i = 0; i < siz; i++)
            data[i + n - 1] = A[i];
        for (int i = n - 2; i >= 0; i--)
            data[i] = fx(data[2 * i + 1], data[2 * i + 2]);
    }
    void update(int i, T x)
    {
        i += n - 1;
        data[i] = gx(data[i], x);
        while (i > 0)
        {
            i = (i - 1) / 2;                                //親へ
            data[i] = fx(data[2 * i + 1], data[2 * i + 2]); //子ノードで更新
        }
    }
    T query(int l, int r) { return sub_query(l, r + 1, 0, 0, n); } //根からスタート
    int find_rightest_min(int l, int r, T x) { return sub_find_rightest_min(x, l, r + 1, 0, 0, n); }
    int find_leftest_min(int l, int r, T x) { return sub_find_leftest_min(x, l, r + 1, 0, 0, n); }
    int find_rightest_max(int l, int r, T x) { return sub_find_rightest_max(x, l, r + 1, 0, 0, n); }
    int find_leftest_max(int l, int r, T x) { return sub_find_leftest_max(x, l, r + 1, 0, 0, n); }
    //data[x]またはdata.at(x)でアクセスできるように
    T operator[](int i) { return data[i + n - 1]; }
    T at(int i) { return data[i + n - 1]; }
};
class FastIO
{
    static const int rdata_sz = (1 << 25), wdata_sz = (1 << 25);
    char rdata[rdata_sz], wdata[wdata_sz], *rb, *wb;
    char tmp_s[20];

public:
    FastIO()
    {
        fread(rdata, 1, rdata_sz, stdin);
        rb = rdata;
        wb = wdata;
    }
    ~FastIO()
    {
        fwrite(wdata, 1, wb - wdata, stdout);
    }

    template <typename T>
    inline void read(T &x)
    {
        bool neg = false;
        x = 0;
        while ((*rb < '0' || *rb > '9') && *rb != '-')
            ++rb;
        if (*rb == '-')
        {
            neg = true;
            ++rb;
        }
        while ('0' <= *rb && *rb <= '9')
        {
            x = 10 * x + (*rb - '0');
            ++rb;
        }
        if (neg)
            x = -x;
    }

#define pc(x) *(wb++) = x
    template <typename T>
    inline void write(T x)
    {
        if (x == 0)
        {
            pc('0');
            pc('\n');
            return;
        }
        if (x < 0)
        {
            pc('-');
            x = -x;
        }
        char *t = tmp_s;
        while (x)
        {
            T y = x / 10;
            *(t++) = (x - y * 10) + '0';
            x = y;
        }
        while (t != tmp_s)
            pc(*(--t));
        pc('\n');
    }
#undef pc
};
int main()
{
    FastIO io;
    unsigned int N, Q;
    io.read(N);
    io.read(Q);
    auto fx = [](unsigned int x, unsigned int y) { return max(x, y); };
    unsigned int id = numeric_limits<unsigned int>::lowest();
    segment_tree<unsigned int> tree(N, id, fx);
    vector<unsigned int> A(N);
    loop(i, N) io.read(A[i]);
    tree.build(A);
    loop(i, Q)
    {
        unsigned int a, b, c;
        io.read(a);
        io.read(b);
        io.read(c);
        if (a == 1)
        {
            b--;
            tree.update(b, c);
        }
        if (a == 2)
        {
            b--;
            c--;
            io.write(tree.query(b, c));
        }
        if (a == 3)
        {
            b--;
            io.write(tree.find_leftest_max(b, N - 1, c) + 1);
        }
    }
    return 0;
}
