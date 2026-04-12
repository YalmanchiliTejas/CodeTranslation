#include<stdio.h>
int a[1000001],b[1000001];
int main(void)
{
	int i,j=1,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++) b[i]=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n%2==0){
		for(i=n;i>=1;i-=2){
			b[j]=a[i];
			j++;
		}
		for(i=1;i<=n;i+=2){
			b[j]=a[i];
			j++;
		}
	}
	if(n%2!=0){
		for(i=n;i>=1;i-=2){
			b[j]=a[i];
			j++;
		}
		for(i=2;i<=n;i+=2){
			b[j]=a[i];
			j++;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d",b[i]);
		if(i==n) printf("\n");
		else  printf(" ");
	}
	return 0;
}