#include <bits/stdc++.h>
#define lli long long int
using namespace std;
#define mod 1000000007
#define mod1 998244353
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main()
{
    fastio;
    int n,s;
    cin >> n >> s;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)
        cin >> v[i];
    vector<vector<int> >vsum(s+1);
    int dp[s+1][n+1];
    for(int sum=1;sum<=s;sum++)
    {
        for(int i=1;i<=n;i++)
        {
            if(v[i]>sum)
            {
                dp[sum][i]=0;
                if(vsum[sum].size()==0)
                    vsum[sum].push_back(0);
                else
                {
                    int t=vsum[sum][vsum[sum].size()-1];
                    vsum[sum].push_back(t);
                }
            }
            else if(v[i]==sum)
            {
                dp[sum][i]=i;
                if(vsum[sum].size()==0)
                    vsum[sum].push_back(i);
                else
                {
                    int t=(vsum[sum][vsum[sum].size()-1]*1LL+i)%mod1;
                    vsum[sum].push_back(t);
                }
            }
            else
            {
                if(i>1)
                    dp[sum][i]=vsum[sum-v[i]][i-2];
                else
                    dp[sum][i]=0;
                int temp=dp[sum][i];
                if(vsum[sum].size()==0)
                    vsum[sum].push_back(temp);
                else
                {
                    int t=(vsum[sum][vsum[sum].size()-1]*1LL+temp)%mod1;
                    vsum[sum].push_back(t);
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+(dp[s][i]*1LL*(n-i+1))%mod1)%mod1;
    cout << ans << endl;
}