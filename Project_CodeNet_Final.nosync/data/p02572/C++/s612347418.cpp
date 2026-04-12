#include<stdio.h>
int main()
{
	int n,a[200000];
	long long int i,x=0,y=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		x+=a[i];
		x=x%(1000000000+7);
	}
	for(i=0;i<n;i++){
		x=x-a[i];
		if(x<0){
			x+=1000000000+7;
		}
		y+=(x*a[i])%(1000000000+7);
		y=y%(1000000000+7);
	}
	printf("%lld\n",y);
	return 0;
}