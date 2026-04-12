#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	if(!k) {
		printf("%lld\n",n*n);
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n-k;++i){
		long long b=k+i;
		ans+=(n/b)*i;
		if(n%b>=k)
		ans+=n%b-k+1; 
	}
	printf("%lld\n",ans);
	return 0;
}