#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const int MAXN=60;
const double eps=1e-10;
LL a[MAXN];

int main()
{
    LL n;
    while(scanf("%lld",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        bool flag=true;
        LL ans=0,div=0;
        int p=0;
        while(flag)
        {
            p=1;
            if(a[p]<n) flag=false;
            for(int i=2;i<=n;i++)
            {
                if(a[i]>a[p]&&a[i]>=n)
                {
                    flag=true;
                    p=i;
                }
            }
            if(flag)
            {
                div=a[p]/n;
                ans+=div;
                a[p]%=n;
                for(int i=1;i<=n;i++)
                    if(i!=p) a[i]+=div;
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}
