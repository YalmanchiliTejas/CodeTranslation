#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll f[3005][3005],a[3005],n;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
    {
        int l=j-i+1,r=j;
        f[l][r]=max(a[l]-f[l+1][r],a[r]-f[l][r-1]);
    }
    printf("%lld",f[1][n]);
    return 0;
}