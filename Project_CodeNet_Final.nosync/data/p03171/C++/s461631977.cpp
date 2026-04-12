#include<bits/stdc++.h>
using namespace std;
long long n,a[3001],dp[3001][3001];
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
          	if(i + j - 1 > n) break;
            if(i == 1) dp[i][j] = a[j];
            else if(i == 2) dp[i][j] = abs(a[j]-a[j+1]);
            else
            {
                int l = j;
                int r = i + j - 1;
                long long t1 = a[r] - dp[i-1][j];
                long long t2 = a[l] - dp[i-1][j+1];
                dp[i][j] = max(t1,t2);
            }
        }
    }
    cout << dp[n][1];
}