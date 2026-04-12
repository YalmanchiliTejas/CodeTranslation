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
/* BIT: 
    BIT<ll> data(n)等で宣言
    構造体内の関数はdata.add(l,x)等で使用
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,x): [l,l+1) に x を加算する(1-indexに注意！！(l>=1))
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    ・query(l,r):[l,r)の区間和を取得する
    ・lower_bound(w):a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
    計算量は全て O(logn)
    (おまけ)
    BITとBIT上での二分探索を活用すると、集合を管理して、
　　・a が何番目に小さいか
　　・w 番目に小さい要素 a は何か
　　というのを以下のように O(logn) で高速に取得することが可能
    add(a,1): 集合への要素 a の追加(a 番目を 1 にする)
　　add(a,-1): 集合への要素 a の削除(a 番目を 1 から 0 にする)
　　sum(a): a が何番目に小さいか
　　lower_bound(w): w 番目に小さい要素 a は何か
*/
template <typename T>
struct BIT
{
private:
    int n; // 配列の要素数(数列の要素数+1)
    vector<T> bit;

public:
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}

    void add(int i, T x)
    {
        for (int idx = i; idx < n; idx += (idx & -idx))
        {
            bit[idx] += x;
        }
    }

    T sum(int i)
    {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx))
        {
            s += bit[idx];
        }
        return s;
    }
    // [l,r) の区間和を取得
    T query(int l, int r) { return sum(r - 1) - sum(l - 1); }
    int lower_bound(T w)
    { // a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
        if (w <= 0)
        {
            return 0;
        }
        else
        {
            int x = 0, r = 1;
            while (r < n)
                r = r << 1;
            for (int len = r; len > 0; len = len >> 1)
            { // 長さlenは1段下るごとに半分に
                if (x + len < n && bit[x + len] < w)
                { // 採用するとき
                    w -= bit[x + len];
                    x += len;
                }
            }
            return x + 1;
        }
    }
};
//配列aの転倒数を高速に求める
ll inversion(vec a)
{
    ll siz = a.size();
    BIT<ll> inv(siz);
    ll ret = 0;
    loop(i, siz)
    {
        ret += (i - inv.sum(a[i]));
        inv.add(a[i], 1);
    }
    return ret;
}
/*
vector<BIT<ll>> bits;
bits.assign(x,n);
で長さnのBITをx本宣言
*/
/* BIT: 
    BIT<ll> data(n)等で宣言
    構造体内の関数はdata.add(l,x)等で使用
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,x): [l,l+1) に x を加算する(1-indexに注意！！(l>=1))
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    ・query(l,r):[l,r)の区間和を取得する
    ・lower_bound(w):a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
    計算量は全て O(logn)
    (おまけ)
    BITとBIT上での二分探索を活用すると、集合を管理して、
　　・a が何番目に小さいか
　　・w 番目に小さい要素 a は何か
　　というのを以下のように O(logn) で高速に取得することが可能
    add(a,1): 集合への要素 a の追加(a 番目を 1 にする)
　　add(a,-1): 集合への要素 a の削除(a 番目を 1 から 0 にする)
　　sum(a): a が何番目に小さいか
　　lower_bound(w): w 番目に小さい要素 a は何か
*/
int main()
{
    cout << fixed << setprecision(30);
    ll N;
    cin >> N;
    vector<ll> A(N);
    loop(i, N) cin >> A[i];
    ll sum = Sum(A);
    BIT<ll> data(N);
    loop(i, N) data.add(1 + i, A[i]);
    ll ans = 0;
    loop(i, N)
    {
        ll z = data.query(i + 2, N + 1);
        ll now = (A[i] * (z % mod)) % mod;
        now %= mod;
        ans += now;
        ans %= mod;
    }
    putout(ans);
    return 0;
}
