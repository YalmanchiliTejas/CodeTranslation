#include<bits/stdc++.h>
using namespace std;

struct p
{
    int a,pos;
}b[200005];
int a[200005];
bool cmp(p b,p c)
{
    return b.a<c.a;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i].a);
        b[i].pos=i;
    }
    sort(b,b+n,cmp);
    int len=n/2;
    for(int i=0;i<len;i++)
        a[b[i].pos]=b[len].a;
    for(int i=len;i<n;i++)
        a[b[i].pos]=b[len-1].a;
    for(int i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
