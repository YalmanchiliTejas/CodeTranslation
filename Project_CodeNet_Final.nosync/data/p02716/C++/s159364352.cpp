#include<bits/stdc++.h>
using namespace std;
long long a[200005],sum[200005],f[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=(i>=2?sum[i-2]:0)+a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(i&1)
        {
            f[i]=max(f[i-2]+a[i],f[i-1]);
        }
        else f[i]=max(f[i-2]+a[i],sum[i-1]);
    }
    cout<<f[n];
}
