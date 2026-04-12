#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main(){
	scanf("%lld%lld",&n,&k);
	for(long long i=k+1;i<=n;i++){
		ans+=(n/i)*(i-k);
		if(n%i>=k)ans+=(n%i-k+1);
	}
	if(k==0)ans-=n;
	printf("%lld",ans);
	return 0;
} 