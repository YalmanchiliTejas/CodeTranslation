#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
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
ull solve(ll x, int level, vll P, vll Len)
{
    if (x == 1)
    {
        return 0;
    }
    if (level == 1)
    {
        return min(3LL, x - 1);
    }
    if (x <= Len[level] / 2)
    {
        return solve(x - 1, level - 1, P, Len);
    }
    if (x == Len[level] / 2 + 1)
    {
        return P[level - 1] + 1;
    }
    else
    {
        return solve(x - Len[level - 1] - 2, level - 1, P, Len) + P[level - 1] + 1;
    }
}
int main()
{
    ll N, X;
    cin >> N >> X;
    vll P(N + 1), B(N + 1), Len(N + 1);
    P[0] = 1;
    Len[0] = 1;
    rep(i, N)
    {
        P[i + 1] = 2 * P[i] + 1;
        B[i + 1] = 2 * B[i] + 2;
        Len[i + 1] = P[i + 1] + B[i + 1];
    }
    ll x = X, level = N, ans = 0;

    cout << solve(X, N, P, Len);
    return 0;
}
