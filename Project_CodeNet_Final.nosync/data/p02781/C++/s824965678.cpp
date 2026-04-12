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

ll Pow(ll x, ll n)
{
    ll ret = 1;
    while (n > 0)
    {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

long long combination(long long N, long long R)
{
    if (R < 0 || R > N)
        return 0;
    if (R == 1)
        return N;
    else if (R == 2)
        return N * (N - 1) / 2;
    else
        return N * (N - 1) * (N - 2) / 6;
}

vector<vvll> memo;
string N;
int K, keta;
ll solve(int i, int k, bool smaller)
{
    if (memo[i][k][smaller] != -1)
    {
        return memo[i][k][smaller];
    }
    if (k == 0)
    {
        memo[i][k][smaller] = 1;
        return 1;
    }
    if (i == keta)
    {
        memo[i][k][smaller] = 0;
        return 0;
    }
    if (smaller)
    {
        memo[i][k][smaller] = combination(keta - i, k) * pow(9, k);
        return memo[i][k][smaller];
    }
    if (N[i] == '0')
    {
        memo[i][k][smaller] = solve(i + 1, k, smaller);
        return memo[i][k][smaller];
    }
    ll zero = solve(i + 1, k, true);
    ll mid = solve(i + 1, k - 1, true) * (N[i] - '1');
    ll girigiri = solve(i + 1, k - 1, false);
    memo[i][k][smaller] = zero + mid + girigiri;
    return memo[i][k][smaller];
}

int main()
{

    cin >> N;
    cin >> K;
    keta = N.size();
    memo.resize(keta + 1, vvll(K+1, vll(2, -1)));

    cout << solve(0, K, false);
    return 0;
}