#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll N;
    cin>>N;
    ll i,a[N],j;
    for(i=0;i<N;i++) cin>>a[i];
    ll dp[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(j+i<N)
            {
                if(i==0) dp[j][j]=a[j];
                else dp[j][j+i]=max(a[j]-dp[j+1][j+i],a[j+i]-dp[j][j+i-1]);
            }
        }
    }
    cout<<dp[0][N-1]<<endl;
    return 0;
}
