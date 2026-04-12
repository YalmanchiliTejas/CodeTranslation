#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node
{
    int x,id;
    bool operator<(const node&o)const
    {
        return x<o.x;
    }
}a[N];
int n,ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].x),a[i].id=i;
    sort(a+1,a+1+n);
    int k=n/2;
    for(int i=1;i<=n;i++)
        if(k<i) ans[a[i].id]=a[k].x;
    else ans[a[i].id]=a[k+1].x;
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
}
