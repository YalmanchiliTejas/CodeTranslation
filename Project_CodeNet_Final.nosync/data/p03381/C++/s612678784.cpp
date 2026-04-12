#include <bits/stdc++.h>

using namespace std;
const int maxn = 200005;

struct P
{
    int i;
    int n;
    int p;
}num[maxn];

bool cmp(P a,P b)
{
    return a.n<b.n;
}

bool cmp1(P a,P b)
{
    return a.i<b.i;
}
void action(){
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
}
int main()
{
    action();
    return 0;
}
