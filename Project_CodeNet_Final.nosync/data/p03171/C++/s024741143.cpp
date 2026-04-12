#include <bits/stdc++.h>
using namespace std;
long long a[3001],f[3001][3001];
int main()
{
        long long i,j,n;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
                scanf("%lld",&a[i]);
                if(n%2==0)
                        f[i][i]=-a[i];
                else
                        f[i][i]=a[i];
        }
        for(j=1;j<=n-1;j++)
        {
                for(i=1;i+j<=n;i++)
                {
                        if((j%2)!=(n%2))
                                f[i][i+j]=max(a[i]+f[i+1][i+j],a[i+j]+f[i][i+j-1]);
                        else
                                f[i][i+j]=min(-a[i]+f[i+1][i+j],-a[i+j]+f[i][i+j-1]);
                }
        }
        printf("%lld",f[1][n]);
        return 0;
}
