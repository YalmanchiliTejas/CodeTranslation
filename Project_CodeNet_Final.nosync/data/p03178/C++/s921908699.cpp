#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int dp[100010][101];
int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    string n;
    int d;
    cin>>n>>d;
    dp[0][0] = 1;
    for(int i=1;i<=100000;i++)
    {
        for(int j=0;j<d;j++)
        {
            int lel = j;
            for(int k=0;k<=9;k++)
            {
                dp[i][j]+=dp[i-1][lel];
                lel--;
                if(lel<0) lel+=d;
            }
            dp[i][j]%=mod;
        }
    }
    int ans = 1e9+6, sm = 0;
    for(int i=0;i<n.size();i++)
    {
        while(n[i]!='0')
        {
            ans += dp[n.size()-i-1][(d-sm)%d];
            sm++;
            sm%=d;
            n[i]--;
        }
        ans%=mod;
    }
    if(sm==0)
        ans=(ans+1)%mod;
    cout<<ans;
    return 0;
}