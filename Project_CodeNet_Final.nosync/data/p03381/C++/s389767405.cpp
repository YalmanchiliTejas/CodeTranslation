#include <cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200005],b[200005];
int main()
{
    int n,i,j,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    x=b[n/2-1];
    y=b[n/2];
    for(i=0;i<n;i++)
    {
        if((lower_bound(b,b+n,a[i])-b)<=n/2-1)
        printf("%d\n",y);
        else printf("%d\n",x);
    }
    return 0;
}
