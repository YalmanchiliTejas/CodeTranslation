#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<long long>a(n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long dp[n+1][n+1];
    for(int L=n-1;L>=0;L--)
    {
        for(int R=0;R<n;R++)
        {
            if(L==R)
            {
                dp[L][R]=a[L];
            }
            else
            {
                dp[L][R]=max(a[L]-dp[L+1][R],a[R]-dp[L][R-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}