#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
//#define mod 998244353ll
#define flagcount __builtin_popcount
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
#define putout(a) cout << a << endl
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
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
最長部分増加列の長さを求める
LIS(A,true):配列Aの狭義最長部分増加列の長さを返す
LIS(A,false):配列Aの広義最長部分増加列の長さを返す
*/
template <typename T>
struct segment_tree
{
private:
    using FX = function<T(T, T)>;
    T n, id; //葉の数、単位元
    vector<T> data;
    FX fx, gx; //区間操作, 点更新操作用
    //[a,b)に対する区間操作　kは[l,r)に対するデータを保持する
    T sub_query(T a, T b, T k, T l, T r)
    {
        if (r <= a || b <= l)
            return id;
        if (a <= l && r <= b)
            return data[k];
        T L = sub_query(a, b, 2 * k + 1, l, (l + r) / 2); //左の子
        T R = sub_query(a, b, 2 * k + 2, (l + r) / 2, r); //右の子
        return fx(L, R);
    }

public:
    segment_tree(T n0, T id0, FX fx0, FX gx0) : n(1), id(id0), fx(fx0), gx(gx0)
    {
        while (n < n0)
            n *= 2;
        data.resize(2 * n - 1, id); //単位元で初期化
    }
    //1点更新クエリの場合はgxを省略できるように
    segment_tree(T n0, T id0, FX fx0) : segment_tree(n0, id0, fx0, [](long long a, long long b) { return b; }) {}
    //配列Aの値で初期化する
    void build(vector<T> A)
    {
        T siz = A.size();
        for (T i = 0; i < siz; i++)
            data[i + n - 1] = A[i];
        for (T i = n - 2; i >= 0; i--)
            data[i] = fx(data[2 * i + 1], data[2 * i + 2]);
    }
    void update(T i, T x)
    {
        i += n - 1;
        data[i] = gx(data[i], x);
        while (i > 0)
        {
            i = (i - 1) / 2;                                //親へ
            data[i] = fx(data[2 * i + 1], data[2 * i + 2]); //子ノードで更新
        }
    }
    T query(T l, T r) { return sub_query(l, r + 1, 0, 0, n); } //根からスタート
    //data[x]またはdata.at(x)でアクセスできるように
    T operator[](T i) { return data[i + n - 1]; }
    T at(T i) { return data[i + n - 1]; }
};
template <typename T>
void press(vector<T> &A)
{
    vector<T> sorted = A;
    sort(sorted.begin(), sorted.end());
    auto itr = unique(sorted.begin(), sorted.end());
    sorted.erase(itr, sorted.end());
    for (int i = 0; i < A.size(); i++)
        A[i] = lower_bound(sorted.begin(), sorted.end(), A[i]) - sorted.begin();
    return;
}
//配列Aの最長増加部分列の長さを求める
template <typename T>
T LIS(vector<T> A, bool strict)
{
    T n = A.size();
    vector<T> B = A;
    press(B);
    auto fx = [](T x, T y) { return max(x, y); };
    T id = numeric_limits<T>::lowest();
    segment_tree<T> tree(n + 1, id, fx);
    vector<T> resiz(n + 1, 0);
    tree.build(resiz);
    T ret = 0;
    for (T i = 0; i < n; i++)
    {
        T maxx;
        if (strict)
            maxx = tree.query(0, B[i]);
        else
            maxx = tree.query(0, B[i] + 1);
        if (tree[B[i] + 1] < maxx + 1)
        {
            tree.update(B[i] + 1, maxx + 1);
            ret = max(ret, maxx + 1);
        }
    }
    return ret;
}
int main()
{
    cout << fixed << setprecision(30);
    ll n;
    cin >> n;
    vector<ll> a(n);
    loop(i, n)
    {
        cin >> a[i];
        a[i] *= -1;
    }
    putout(LIS(a, false));
    return 0;
}