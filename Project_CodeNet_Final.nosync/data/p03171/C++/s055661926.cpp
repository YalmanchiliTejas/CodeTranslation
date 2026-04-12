#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[3010][3010];
int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        dp[i][i] = v[i];
    }
    for(int len=1;len<n;len++)
    {
        for(int i=0;i<n-len;i++)
        {
            int j=i+len;
            dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}