#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;
int ans[maxn];
struct edge{
    int x,id;
}a[maxn];
bool cmp(const edge& a,const edge& b){return a.x<b.x;}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i].x),a[i].id=i;
        sort(a+1,a+n+1,cmp);
        int l=(1+n)/2;
        for(int i=1;i<=n/2;i++)
            ans[a[i].id]=a[l+1].x,ans[a[i+n/2].id]=a[l].x;
        for(int i=1;i<n;i++)printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
}