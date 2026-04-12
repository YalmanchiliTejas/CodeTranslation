#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200001],b[200001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memcpy(b,a,sizeof(a));
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    	if (b[i]<a[n/2+1])printf("%d\n",a[n/2+1]);
    	else printf("%d\n",a[n/2]);
}