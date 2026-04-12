#include <stdio.h>

typedef long long lli;

int main() {
	lli n, k;
	scanf("%lld %lld",&n,&k);
	if(k==0) {
		printf("%lld\n",n*n);
		return 0;
	}
	lli res=0;
	for(lli a=k+1;a<=n;a++) {
		for(lli b=a;b<=n;b+=a) {
			res+=a-k;
		}
		lli rem=n%a;
		if(rem==0) continue;
		if(rem>k-1) res+=rem-k+1;
	}
	printf("%lld\n",res);
	return 0;
}