#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 200010
typedef struct
{
    int u,v,w;
}Node;
Node e[N];
int cmp1(Node a,Node b)
{
    return a.u<b.u;
}
int cmp2(Node a,Node b)
{
    return a.v<b.v;
}
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&e[i].u);
        e[i].v=i;
    }
    sort(e,e+n,cmp1);
    k=n/2;
    for(i=0;i<n;i++)
    {
        if(i>=k)
            e[i].w=e[k-1].u;
        else
        if(i<k)
        e[i].w=e[k].u;
    }
    sort(e,e+n,cmp2);
    for(i=0;i<n;i++)
        printf("%d\n",e[i].w);
    return 0;
}
