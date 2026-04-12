#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll al[200010],mod=1e9+7,sum[200010],anss=0,n;
int main(){
	scanf("%lld",&n);
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;++i){
		scanf("%lld",&al[i]);
		sum[i]=(sum[i-1]+al[i])%mod;
	}
	for(int i=1;i<=n-1;++i)
		anss=(anss+al[i]*(sum[n]-sum[i]+mod))%mod;
	printf("%lld\n",anss);
	return 0;
	
}