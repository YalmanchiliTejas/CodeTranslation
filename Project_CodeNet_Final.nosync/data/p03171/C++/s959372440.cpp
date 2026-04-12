#include <bits/stdc++.h>
using namespace std;
#define FAST std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define pb push_back
#define mod 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define int long long int
signed main() 
{
    FAST
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    std::vector<int> v(n);
    fr(i,n) cin>>v[i];
    std::vector<std::vector<int> > dp;
    std::vector<int> row(n,0);
    fr(i,n) dp.pb(row);

    fr(i,n) dp[i][i]=v[i];

    for(int j=1;j<n;j++)
    {
        fr(i,n)
        {
            if(i+j>=n) break;

            dp[i][i+j]=max(v[i]-dp[i+1][i+j],v[i+j]-dp[i][i+j-1]);

        }
    }

    cout<<dp[0][n-1];

    return 0;
}   