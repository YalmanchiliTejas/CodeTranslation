#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

ll dp[100], dp2[100];

// |B|l-1|P|l-1|B|
ll dnc(int n, ll x)
{
    if (n == 0)
        return 1;
    if (x == 0)
        return 0;
    if (x == dp2[n] / 2)
        return 1 + dp[n - 1];
    if (x < dp2[n] / 2)
        return dnc(n - 1, x - 1);
    return dp[n - 1] + 1 + dnc(n - 1, x - dp2[n - 1] - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    dp[0] = 1;
    dp2[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 2 * dp[i - 1] + 1;
        dp2[i] = 2 * dp2[i - 1] + 3;
    }
    cout << dnc(n, x - 1);
}
