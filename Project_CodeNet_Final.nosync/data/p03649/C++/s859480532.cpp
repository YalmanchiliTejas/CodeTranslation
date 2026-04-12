#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[55];
long long res=0;
bool cmp(long long a,long long b) {
	return a>b;
}
int main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	long long ma=a[1];
	while(ma>n-1) {
		long long tmp=ma/n;
		a[1]=ma%n;
		res+=tmp;
		for(int i=2;i<=n;i++)
				a[i]+=tmp;
		sort(a+1,a+n+1,cmp);
		ma=a[1];
	}
	printf("%lld\n",res);
	return 0;
}