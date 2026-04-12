#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

long long a[100015];

int main(){
	
	long long n,i,lv,rv,ans;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	lv=a[1];
	rv=a[n];
	ans=a[n]-a[1];
	for(i=2;i+i<=n;i++){
		ans+=a[n-i+1]-lv;
		ans+=rv-a[i];
		lv=a[i];
		rv=a[n-i+1];
	}
	if(n&1)ans+=max(rv-a[i],a[i]-lv);
	printf("%lld",ans);
	return 0;
}
		
	