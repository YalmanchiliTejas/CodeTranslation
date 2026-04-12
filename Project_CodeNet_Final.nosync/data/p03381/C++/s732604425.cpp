#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=2e5+10;

struct datum {int v,p,re;}z[maxn];

int n;

bool cmp1(datum a,datum b)
{
    return a.v<b.v;
}

bool cmp2(datum a,datum b)
{
    return a.p<b.p;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&z[i].v),z[i].p=i;

    sort(z+1,z+1+n,cmp1);
    for(int i=1;i<=n/2;i++)
        z[i].re=z[n/2+1].v;
    for(int i=n/2+1;i<=n;i++)
        z[i].re=z[n/2].v;

    sort(z+1,z+1+n,cmp2);
    for(int i=1;i<=n;i++)
        printf("%d\n",z[i].re);

    return 0;
}