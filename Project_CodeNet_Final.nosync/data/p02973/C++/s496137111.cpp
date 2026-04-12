#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    reverse(a.begin(), a.end());

    vector<int> dp(n + 1, inf);
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[idx] = a[i];
    }

    for (int i = n; i >= 0; i--)
    {
        if (dp[i] != inf)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}