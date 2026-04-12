// https://atcoder.jp/contests/abc054/tasks/abc054_c
// 再帰DFS で全通りの経路を見る
// 引数に今いるノードと探索したノードを渡す
// 全部のノードに到達したら1カウント
#include <bits/stdc++.h>
using namespace std;
#define int long long
using P = pair<int, int>;
constexpr array<int, 4> dx = {1, 0, -1, 0};
constexpr array<int, 4> dy = {0, 1, 0, -1};
constexpr int INF = 1234567890;
constexpr int MOD = 1000000000 + 7;
// constexpr int MOD = 998244353;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
constexpr int fact(int n) { return n > 1 ? n * fact(n - 1) % MOD : 1; }
int modinv(int a)
{
    int b = MOD, u = 1, v = 0;
    while (b)
    {
        int t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if (u < 0)
        u += MOD;
    return u;
}
constexpr int modpow(int a, int n)
{
    int rtn = 1;
    while (n > 0)
    {
        if (n & 1)
            rtn = rtn * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return rtn;
}

int n, m;
// パスを表す
vector<vector<int>> to;

int dfs(int here, int seen)
{
    // 全部のノードにたどり着ける経路を数える
    static int count = 0;

    // 全部のノードにたどり着いているか
    if (seen == pow(2, n) - 1)
        count++;

    // 今いるノードにつながった辺について調べる
    for (auto &&next : to[here])
    {
        // 次のノードを探索してないかどうか
        if (seen & 1 << next)
            continue;
        // 次のノードに移動
        dfs(next, seen | 1 << next);
    }

    return count;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10);

    cin >> n >> m;
    to.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a - 1].push_back(b - 1);
        to[b - 1].push_back(a - 1);
    }

    // ノード0から探索する 第2引数はノード0を探索したことを意味する
    cout << dfs(0, 0b1) << endl;
}
