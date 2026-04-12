#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
using namespace std;
int mes[200010];
int main()
{
    int n;
    scanf("%d",&n);
    ff(i,1,n)
    scanf("%d",&mes[i]);
    if(n%2)
    {
        for(int i=n;i>=1;i-=2)
        printf("%d ",mes[i]);
        for(int i=2;i<=n-1;i+=2)
        printf("%d ",mes[i]);
    }
    else
    {
        for(int i=n;i>=2;i-=2)
        printf("%d ",mes[i]);
        for(int i=1;i<=n-1;i+=2)
        printf("%d ",mes[i]);
    }
    return 0;
}
