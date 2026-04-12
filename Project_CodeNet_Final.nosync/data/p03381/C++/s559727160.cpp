#include <bits/stdc++.h>

using namespace std;

struct node
{
    int i;
    int n;
    int p;
}num[200010];

bool cmp(node aa,node bb)
{
    return aa.n<bb.n;
}

bool cmp1(node aa,node bb)
{
    return aa.i<bb.i;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i].n);
        num[i].i=i;
    }
    sort(num,num+n,cmp);
    int mid=n/2;
    for(int i=0;i<n;i++)
    {
        if(num[i].n<num[mid].n)
            num[i].p=num[mid].n;
        else
            num[i].p=num[mid-1].n;
    }
    sort(num,num+n,cmp1);
    for(int i=0;i<n;i++)
        printf("%d\n",num[i].p);
    return 0;
}
