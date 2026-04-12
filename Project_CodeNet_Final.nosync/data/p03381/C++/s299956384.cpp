#include<cstdio>
#include<algorithm>
int main(){
	int n;
	scanf("%d",&n);
	long long int a[n]={};
	long long int b[n]={};
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	std::sort(b,b+n);
	long long int x=b[n/2-1];
	long long int y=b[n/2];
	for(int i=0;i<n;i++){
		if(a[i]<=x)printf("%lld\n",y);
		else printf("%lld\n",x);
	}
	return 0;
}