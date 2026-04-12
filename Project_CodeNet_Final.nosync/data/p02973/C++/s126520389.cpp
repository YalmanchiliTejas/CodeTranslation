#include <stdio.h>
#include <vector>

using namespace std;

int a[100010],f[100010];

int main()
{
    int n;scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    int ans=0;f[0]=1e9+1;
    for (int i=0;i<n;++i){
        int tmp=0;
        int ll=1,rr=ans;
        while (ll<=rr){
            int mid=(ll+rr)/2;
            if (f[mid]>=a[i]){
                tmp=mid;ll=mid+1;
            }
            else rr=mid-1;
        }
        if (f[tmp+1]<a[i]) f[tmp+1]=a[i];
        if (tmp+1>ans) ans=tmp+1;
    }
    printf("%d\n",ans);
}

