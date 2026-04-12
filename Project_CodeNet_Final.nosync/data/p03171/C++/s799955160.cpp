#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

ll n, a[3000], dp[3000][3000];

ll f(int p, int q)
{
    if (p > q) return 0;
    if (dp[p][q] != -1) return dp[p][q];
    return dp[p][q] = max(a[p] - f(p + 1, q), a[q] - f(p, q - 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    cout << f(0, n - 1);
}
