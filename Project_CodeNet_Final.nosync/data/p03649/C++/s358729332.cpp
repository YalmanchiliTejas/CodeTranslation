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
        LL* p;
        LL ans=0;
        while(*(p=max_element(a+1,a+n+1))>=n)
        {
            for(int i=1;i<=n;i++)
                if(a+i!=p)
                a[i]+=(*p)/n;
            ans+=(*p)/n;
            (*p)%=n;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
