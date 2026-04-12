#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int  a[maxn];
int dp[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n/2;i++)
    swap(a[i],a[n-i+1]);
     dp[1]=a[1];
    int k=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]+1>dp[k])
        dp[++k]=a[i];
        else
        {
            dp[upper_bound(dp+1,dp+1+k,a[i])-dp]=a[i];
        }
    }
    cout<<k<<endl;

    return 0;
}
