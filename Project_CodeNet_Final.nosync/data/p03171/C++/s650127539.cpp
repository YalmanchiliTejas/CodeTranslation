#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    vector<ll> a(n);
    for(ll& x: a)
        scanf("%d", &x);
    vector<vector<vector<ll>> > dp(n+1, vector<vector<ll> > (n+1 , vector<ll> (2)) );
    for(int l =1; l<= n;l++)
    {
        for(int i = 1; i + l -1 <=n; i++)
        {
            int j = i + l -1;
            if(i==j)
                dp[i][j][0] = dp[i][j][1] = a[i-1];
            else 
                {
                    dp[i][j][0] = max(a[i-1]  - dp[i+1][j][1] , a[j-1] - dp[i][j-1][1]);
                    dp[i][j][1] = max(a[i-1] - dp[i+1][j][0] , a[j-1] - dp[i][j-1][0]);
                }
        }
    }
    cout<<dp[1][n][0]<<"\n";

}