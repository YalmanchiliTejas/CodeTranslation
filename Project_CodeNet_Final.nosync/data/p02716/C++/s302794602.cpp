#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

ll a[200000];
ll dp[200000][3];
int n;

ll f(int i, int s)
{
    if (i >= n)
        return 0;
    ll& sol = dp[i][s];
    if (sol != -1)
        return sol;
    sol = a[i] + f(i + 2, s);
    if (s > 0)
        sol = max(sol, f(i + 1, s - 1));
    return sol;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << f(0, n % 2 + 1);
}
