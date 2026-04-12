#include <bits/stdc++.h>
using namespace std;
struct num
{
    int data;
    int n;
}a[200005];
bool cmp(num x,num y)
{
    return x.data<y.data;
}
int main()
{
    int N,i,j,l,r,b[200005];
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        {scanf("%d",&a[i].data);
        a[i].n=i;
        }
    sort(a+1,a+N+1,cmp);
    r=a[N/2+1].data;
    l=a[N/2].data;
    for(i=1;i<=N;i++)
    {
        if(i<=N/2)
            b[a[i].n]=r;
        else
             b[a[i].n]=l;
    }
    for(i=1;i<=N;i++)
    {
        printf("%d",b[i]);
        if(i!=N)
            printf("\n");
    }
    return 0;
}