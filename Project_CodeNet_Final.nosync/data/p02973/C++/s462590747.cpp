//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int inf = 1e9 + 10;

int a[N], dp[N];

bool isVal(int x, int y)
{
    return (y <= dp[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[n - i];
    for (int i = 1; i <= n; i ++)
        a[i] = -a[i];
    fill(dp, dp + N, -inf);
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; i ++)
    {
        int l = 0, r = n + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (isVal(mid, a[i]))
                l = mid;
            else
                r = mid;
        }
        dp[l + 1] = a[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; i ++)
        if (dp[i] != -inf)
            ans = i;
    cout << ans;
    return 0;
}
