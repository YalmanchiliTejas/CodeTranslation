#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define mod 1e9+7
using namespace std;
ll dp[3001][3001][2];
ll arr[3001];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);
    for(int i=0; i<n; i++)
    {
        dp[i][i][0]=arr[i];
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; (i+j)<n; j++)
        {
            //cout<<j<<" "<<i<<endl;
            ll t1=arr[(i+j)]+dp[j][(i+j)-1][1];
            ll q1=dp[j][(i+j)-1][0];
            ll t2=arr[j]+dp[j+1][(i+j)][1];
            ll q2=dp[j+1][(i+j)][0];
            if(t1>t2)
            {
                dp[j][(i+j)][0]=t1;
                dp[j][(i+j)][1]=q1;
            }
            else
            {
                dp[j][(i+j)][0]=t2;
                dp[j][(i+j)][1]=q2;
            }
        }
    }
    printf("%lld\n", dp[0][n-1][0]-dp[0][n-1][1]);
    return 0;
}
