#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> dp(n);
    dp[0] = h[0];
    for(int i = 1; i < n; i++)
        dp[i] = max(h[i], dp[i - 1]);
    int ans = 1;
    for(int i = 1; i < n; i++)
    {
        if(dp[i - 1] <= h[i])
            ans++;
    }

    cout << ans;

    return 0;
}
