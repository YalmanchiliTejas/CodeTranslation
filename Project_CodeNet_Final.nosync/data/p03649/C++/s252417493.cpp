#include <cstdio>

using namespace std;

long long v[55],v1[55];

int main()
{
    //freopen("file.in","r",stdin);
    //freopen("file.out","w",stdout);
    int n;
    long long sol=0,c=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    while(1)
    {
        int p=0;
        for(int i=1;i<=n;i++)
        {
            c+=v1[i];
            v[i]+=c;
            v1[i]=0;
            if(v[i]>=n)
            {
                p=1;
                long long x=v[i]/n;
                v[i]-=1LL*x*n;
                sol+=x;
                v1[1]+=x;
                v1[i]-=x;
                v1[i+1]+=x;
            }
        }
        c=0;
        if(p==0) break;
    }
    printf("%lld",sol);
    return 0;
}
