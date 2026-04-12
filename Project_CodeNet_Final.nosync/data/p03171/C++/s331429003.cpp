#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

int pref[3005] = {0}, dp[3005][3005] = {0};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> pref[i], dp[i][i] = pref[i], pref[i] += pref[i-1];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j+i-1 <= n; j++)
            dp[j][j+i-1] = max(dp[j][j] + pref[j+i-1] - pref[j] - dp[j+1][j+i-1], dp[j+i-1][j+i-1] + pref[j+i-2] - pref[j-1] - dp[j][j+i-2]);
    cout << dp[1][n] - (pref[n] - dp[1][n]) << endl;
}