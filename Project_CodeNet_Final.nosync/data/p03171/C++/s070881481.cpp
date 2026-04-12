#include <bits/stdc++.h>

using namespace std;

long long dp[3005][3005];
long long a[3005];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i=0;i<n;i++)
        cin >> a[i];

    for (int i=n;i>=0;i--)
        for(int j=i;j<n;j++)
        dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);

    cout << dp[0][n-1];
}
