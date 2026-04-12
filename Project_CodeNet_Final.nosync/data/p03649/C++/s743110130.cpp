#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 100

LL n,a[N],ans;

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	while (1){
		bool fl=0;
		for (LL i=1;i<=n;++i)
			if (a[i]+ans>=n){
				fl=1;
				LL t=(a[i]+ans)/n;
				ans+=t;
				a[i]-=t*(n+1);
			}
		if (!fl) break;
	}
	printf("%lld\n",ans);
	
	return 0;
}
			