#include<bits/stdc++.h>

using namespace std;

int n,k;
long long ans = 0;

int main(){
	scanf("%d %d",&n,&k);
	for(int i=k+1;i<=n;i++){
		ans += (n/i) * (i-k);
		ans += max(0,n%i-k+(k!=0));
	}
	printf("%lld\n",ans);	
	return 0;
}