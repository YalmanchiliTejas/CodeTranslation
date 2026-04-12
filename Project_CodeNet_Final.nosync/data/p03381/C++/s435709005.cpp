#include <cstdio>
#include <algorithm>

using namespace std;

int g[300000],h[300000];
int i,n;

int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&g[i]);
    for (i=1;i<=n;i++)
        h[i]=g[i];
    sort(h+1,h+n+1);
    for (i=1;i<=n;i++)
        if (g[i]<=h[n/2])
        	printf("%d\n",h[n/2+1]);
        else
        	printf("%d\n",h[n/2]);
    return 0;
}