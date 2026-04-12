#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
long long k,n,m,ans;
int main(){
	scanf("%lld%lld%lld",&k,&n,&m);
	if(k<=n) {
		printf("1\n");
		return 0;
	}
	if(n<=m) {
		printf("-1\n");
		return 0;
	}
	long long s=n-m,d=k-n;
	if(d%s==0) ans=d/s;
		else ans=d/s+1;
	printf("%lld\n",ans*2+1);
}

