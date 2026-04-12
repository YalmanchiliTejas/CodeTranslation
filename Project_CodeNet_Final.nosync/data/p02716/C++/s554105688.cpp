#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
const ll INF = (ll) 1e18;
int n;
int a[N];
map<pair<int, int>, ll> sol;

ll solve(int p, int k)
{
    if ((p + 1) / 2 < k)
    {
        return -INF;
    }
    if (sol.count({p, k}))
    {
        return sol[{p, k}];
    }
    if (k == 0)
    {
        sol[{p, k}] = 0;
        return 0;
    }
    ll ans = max(solve(p - 1, k), a[p] + solve(p - 2, k - 1));
    sol[{p, k}] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << solve(n, n / 2) << "\n";
}