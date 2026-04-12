#include <bits/stdc++.h>
int n,k;
long long ans;
int main(){
	scanf("%d%d",&n,&k);
	if (k==0){
		printf("%lld\n",1ll*n*n);
		return 0;
	}
	for (int i=k;i<=n;i++){
		ans+=n-i;
		int t=n/i;
		ans+=(t-1)*(i-k);
		if (n%i>=k) ans+=n%i-k+1;
	}
	printf("%lld\n",ans);
} 