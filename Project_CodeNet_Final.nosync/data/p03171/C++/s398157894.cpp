#include <bits/stdc++.h>
using namespace std;
const int nax = 3005;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<ll>> dp(nax,vector<ll>(nax,0));
    
    for(auto &it:a)
    {
        cin >> it;
    }

    for(int i=n-1;i>=0;--i)
    {
        for(int j=i;j<n;++j)
        {
            if(i==j)
            dp[i][j]=a[i];
            else
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    
   cout << dp[0][n-1] << endl;
    
    return 0;
}