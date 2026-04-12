#include<bits/stdc++.h>

using namespace std;

#define LL long long

LL n,m,ans;

int main(){
	scanf("%lld%lld",&n,&m);
	if (m==0){
		printf("%lld\n",n*n);
		return 0;
	}
	for (int i=1;i<=n;i++){
		if (n%i==0){
			if (i>m) ans+=n/i*(i-m);
		}
		else{
			int j=n%i;
			if (j>=m) ans+=j-m+1;
			if (i>m) ans+=n/i*(i-m);
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}
			