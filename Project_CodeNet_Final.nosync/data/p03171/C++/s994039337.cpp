#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define deb(x) cout<<#x<<" is "<<x<<endl;
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)   
        cin>>a[i];

    ll dp[n][n][2];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<=n-1;j++)
        {
            if(i==j)
            {
                dp[i][j][0]=a[i];
                dp[i][j][1]=-a[i];
            }
            else
            {
                //consider range a[i...j]
                //take "i", or take "j" and maximise or minimise according to your objective
                dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
                dp[i][j][1]=min(-a[i]+dp[i+1][j][0],-a[j]+dp[i][j-1][0]);    
            }

            // cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        }
    }
    cout<<dp[0][n-1][0]<<endl;
}