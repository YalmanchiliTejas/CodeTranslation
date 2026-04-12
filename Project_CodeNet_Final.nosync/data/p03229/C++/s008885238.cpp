#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int d[100010];
int main()
{
    int n;
    long long sum=0,sum1=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        b[n-i+1]=a[i];
    int r=1;
    for(int i=1;i<=n/2;i++)
    {
        c[r++]=b[i];d[r-1]=a[i];
        c[r++]=a[i];d[r-1]=b[i];
    }
    if(n&1)
    {
        for(int i=2;i<r;i++)
            sum+=abs(c[i]-c[i-1]),sum1+=abs(d[i]-d[i-1]);

        sum+=max(abs(c[n-1]-a[n/2+1]),abs(c[1]-a[n/2+1]));
        sum1+=max(abs(d[n-1]-a[n/2+1]),abs(d[1]-a[n/2+1]));
        if(sum<sum1)
            sum=sum1;
        printf("%lld\n",sum);
    }
    else
    {
        for(int i=2;i<r-1;i++)
            sum+=abs(c[i]-c[i-1]);
        sum+=max(abs(c[n-1]-a[n/2]),abs(c[1]-a[n/2]));
        printf("%lld\n",sum);
    }
    return 0;
}
