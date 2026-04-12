#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll INF = 1e18;
int N;
ll a[3009], pre[3009];
ll dp[3009][3009];

ll sum(int l, int r) { return pre[r] - pre[l - 1]; }

ll solve(int l, int r)
{
    if (l > r) return -INF - 1;

    if (dp[l][r] != -INF)
    {
        return dp[l][r];
    }

    if (l == r) return dp[l][r] = a[l];

    if (solve(l + 1, r) < solve(l, r - 1))
    {
        return dp[l][r] = sum(l, r) - solve(l + 1, r);
    }
    else
    {
        return dp[l][r] = sum(l, r) - solve(l, r - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = -INF;
        }
    }

    ll X = solve(1, N);
    ll Y = sum(1, N) - solve(1, N);

    cout << X - Y << "\n";
}