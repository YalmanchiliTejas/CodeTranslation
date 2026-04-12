#include<iostream>
#include<cstdio>
#define MAXN 1000000007
using namespace std;
long long n,a[200010],b[200010],sum=0,ans=0;
int main(){
	scanf("%d",&n);
	b[0]=0;
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum=(sum+a[i])%MAXN;
		b[i]=(b[i-1]+a[i])%MAXN;
	}
	for(register int i=1;i<n;i++){
		long long use=(sum+MAXN-b[i])%MAXN;
		ans=(ans+(use*a[i])%MAXN)%MAXN;
	}
	cout<<ans<<'\n';
	return 0;
}