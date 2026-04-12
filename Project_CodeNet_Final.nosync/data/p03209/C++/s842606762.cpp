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

vector<ull> P, length;

ull solve(ull x, int level)
{
    if(x==1)
    {
        return 0;
    }
    if (level == 1)
    {
        return min((ull)3, x - 1);
    }
    if (x <= length[level] / 2)
    {
        return solve(x - 1, level - 1);
    }
    else if (x == length[level] / 2 + 1)
    {
        return P[level-1] + 1;
    }
    else
    {
        return solve(x - length[level - 1] - 2, level - 1) + P[level - 1] + 1;
    }
}

int main()
{
    ull N, X;

    cin >> N >> X;
    ull ans = (ull)0;
    P.resize(N + 1);
    length.resize(N + 1);
    //  vector<vector<ull>> dp(51, vector<ull>(X + 1));
    P[0] = 1;
    length[0] = 1;
    rep(i, N)
    {
        P[i + 1] = 2 * P[i] + 1;
        length[i + 1] = 2 * length[i] + 3;
    }
    /*rep(i,N)
    {
        ull tmp = 0;
        if(X<=length[i+1]/2)
        {
            tmp = dp[i][X];
        }
        else if (X == length[i + 1] / 2+1)
        {
            tmp = dp[i][X] + 1;
        }
        dp[i + 1][X] =
    }*/
    /*   for (int i = N; i > 0;i--)
    {
        if(X<i)
        {
            break;
        }
        X -= i;
        ans += min(X, P[i-1]);
        X -= min(X, P[i - 1]);
        if (X < i)
        {
            break;
        }
        X -= i;
    }
    */
    cout << solve(X, N);
    return 0;
}