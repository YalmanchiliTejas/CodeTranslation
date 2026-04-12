#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define INF 1145141919
#define LLINF 1145148101919
#define PI 3.14159265359
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int ny, nx;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

ll llpow(ll x, ll y)
{
    ll ans = 1;
    REP(i, y)
    ans *= x;
    return ans;
}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}

class UnionFind
{
public:
    vector<ll> par; // 各元の親を表す配列
    vector<ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL)
    {
        for (ll i = 0; i < sz_; ++i)
            par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_)
    {
        siz.assign(sz_, 1LL); // assign: 再代入
        par.resize(sz_);      // resize: 再確保
        for (ll i = 0; i < sz_; ++i)
            par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x)
    { // 根の検索
        while (par[x] != x)
        {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y)
    { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x)
    { // 素集合のサイズ
        return siz[root(x)];
    }
};

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename Container>
bool exist_in(const Container &c, const typename Container::value_type &v)
{
    return (c.end() != std::find(c.begin(), c.end(), v));
}

int ctoi_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    return 0;
}

const int MOD = 1000000007;
// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int>> calcNext(const string &S)
{
    int n = (int)S.size();
    vector<vector<int>> res(n + 1, vector<int>(26, n));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
            res[i][j] = res[i + 1][j];
        res[i][S[i] - 'a'] = i;
    }
    return res;
}
// mod 1000000007 の世界で a += b する関数
void add(long long &a, long long b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

//std::cout << std::defaultfloat << std::setprecision(10);
////////////////////////////////////////
int main()
{
    int n,m; cin >> n >> m;

    if(n==m) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}