#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100001],f[100001],d[100001],ans=1,t=0;
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
    ans=1;
    t=0;
    for(i=1;i<=n;i++) {
        f[i]=1;
        for(j=t;j>0;j--)
            if(a[i]<=a[d[j]]) {
                f[i]=f[d[j]]+1;
                break;
            }
        t=max(t,f[i]);
        d[f[i]]=i;
        ans=max(ans,f[i]);
    }
    printf("%d",ans);
    return 0;
}