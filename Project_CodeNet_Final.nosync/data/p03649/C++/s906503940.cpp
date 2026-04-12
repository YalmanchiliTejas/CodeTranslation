#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j;
long long x,y,s,a[54];
bool ok;
int main()
{
    scanf ("%d", &n);
    for (i=1;i<=n;i++)
        scanf ("%lld", &a[i]);
    sort (a+1,a+n+1);
    s=0LL;
    for (i=1;i<=(n-1);i++)
    {
        x=(0LL)+a[i+1]-a[i];
        x=(1LL)*x/(n+1);
        s=(0LL)+s+(1LL)*x*(n-i);
        for (j=1;j<=i;j++)
            a[j]=(0LL)+a[j]+(1LL)*x*(n-i);
        for (j=(i+1);j<=n;j++)
            a[j]=(0LL)+a[j]-(1LL)*x*(i+1);
    }
    y=(0LL)+a[1]-n;
    if (y>0)
    {
        s=(0LL)+s+(1LL)*y*n;
        for (i=1;i<=n;i++)
            a[i]=(0LL)+a[i]-y;
    }
    ok=true;
    while (ok==true)
    {
        ok=false;
        for (i=1;i<=n;i++)
        {
            if (a[i]>=n)
            {
                ok=true;
                break;
            }
        }
        if (ok==false)
            break;
        else
        {
            s=(0LL)+s+1;
            for (j=1;j<i;j++)
                a[j]=(0LL)+a[j]+1;
            for (j=(i+1);j<=n;j++)
                a[j]=(0LL)+a[j]+1;
            a[i]=(0LL)+a[i]-n;
        }
    }
    printf ("%lld", s);
    return 0;
}
