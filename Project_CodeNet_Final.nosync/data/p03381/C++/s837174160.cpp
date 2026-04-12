#include <bits/stdc++.h>
using namespace std;
int n,i,j,a[200005],b[200005];
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",a+i);
	memcpy(b,a,sizeof(a));
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++){
		if (b[i]<=a[n/2]) printf("%d\n",a[n/2+1]); else printf("%d\n",a[n/2]);
	}
	return 0;
}