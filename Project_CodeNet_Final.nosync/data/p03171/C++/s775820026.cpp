#include <bits/stdc++.h>
long long dpmax[3005][3005],dpmin[3005][3005];
int n,a[3005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		dpmax[i][i]=a[i],dpmin[i][i]=-a[i];
		for (int j=i+1;j<=n;j++) dpmax[i][j]=-100000000000,dpmin[i][j]=10000000000;
	}
	
	for (int i=2;i<=n;i++)
		for (int l=1,r=i;r<=n;l++,r++){
			dpmax[l][r]=std::max(dpmin[l+1][r]+a[l],dpmin[l][r-1]+a[r]);
			dpmin[l][r]=std::min(dpmax[l+1][r]-a[l],dpmax[l][r-1]-a[r]);
		}
	printf("%lld\n",dpmax[1][n]);
}