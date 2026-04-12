//In the Name of ̲A̲l̲l̲a̲h̲

#define pb push_back
#define F first
#define S second
#define sz size()
#define ll long long

#include <bits/stdc++.h>

using namespace std;

ll n, dp[3001][3001], a[3001], dp2[3001][3001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i][i] = dp2[i][i] = a[i];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i-1][i] = max(a[i]-a[i-1] , a[i-1]-a[i]);
        dp2[i-1][i] = min(a[i]-a[i-1] , a[i-1]-a[i]);
    }
    for (int j = 2; j < n; j++)
    {
        for (int i = 0; i+j < n; i++)
        {
            dp2[i][i+j] = min(dp[i+1][i+j]-a[i],dp[i][i+j-1]-a[i+j]);
            dp[i][i+j] = max(dp2[i+1][i+j]+a[i],dp2[i][i+j-1]+a[i+j]);
        }
    }
    cout << dp[0][n-1];
}

/*𝐻𝒶𝒹𝒾*/
