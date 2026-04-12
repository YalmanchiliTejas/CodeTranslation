#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dp(n, INT32_MAX);

    for (int i = n - 1; i >= 0; --i)
    {
        int pos = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[pos] = a[i];
    }

    int ans = 0;
    for (int i : dp)
        if (i == INT32_MAX)
            break;
        else
            ++ans;
    cout << ans << endl;
}
