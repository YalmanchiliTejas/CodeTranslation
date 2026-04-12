#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[100005],LIS[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)LIS[i]=1;
	for(int i=1;i<=n;i++){
		int t=upper_bound(LIS+1,LIS+n+1,-a[i])-LIS;
		while(t>1&&LIS[t-1]>-a[i])t--;while(t<n&&LIS[t]<-a[i])t++;
		LIS[t]=-a[i];
	}
	int t=upper_bound(LIS+1,LIS+n+1,1)-LIS;
	while(t>1&&LIS[t-1]==1)t--;while(t<n&&LIS[t]<1)t++;
	printf("%d\n",t-1);
	return 0;
}