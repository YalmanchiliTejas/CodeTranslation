#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[30010],dp[30010];
int main()
{
    ll n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j+i-1<=n; j++)
        {
            dp[j]=max(a[j]-dp[j+1],a[j+i-1]-dp[j]);
        }
    }

    cout<<dp[1]<<endl;
}
