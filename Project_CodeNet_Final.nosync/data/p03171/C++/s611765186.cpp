#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int N;
vector<ll> a(3000);
// dp[i][j] = max{First - Second}
vector<vector<ll>> dp(3000, vector<ll>(3000, -1e15));

ll calc(int l, int r, int turn)
{
    if (dp[l][r] != -1e15)
    {
        return dp[l][r];
    }
    if (l == r)
    {
        if (turn == 0)
        {
            return dp[l][r] = a[l];
        }
        else
        {
            return dp[l][r] = -a[l];
        }
    }
    if (turn == 0)
    {
        dp[l][r] = max(a[l] + calc(l + 1, r, 1), calc(l, r - 1, 1) + a[r]);
    }
    else
    {
        dp[l][r] = min(-a[l] + calc(l + 1, r, 0), calc(l, r - 1, 0) - a[r]);
    }
    return dp[l][r];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    cout << calc(0, N - 1, 0) << endl;
}