#include<stdio.h>
int main(void)
{
	int i,n,a[200000],x,y;
	scanf("%d",&n);
	x=n/2; y=x-1;
	i=0;
	while(i<n){
		scanf("%d",&a[x]); //printf("x=%d,%d,",x,a[x]); 
		x++; i++;
		if(i==n) break;
//		if(y<0) break;
		scanf("%d",&a[y]); //printf("y=%d,%d,\n",y,a[y]); 
		y--; i++;
	}
//	printf("y=%d,%d,x=%d,%d,\n",y,a[y],x,a[x]);
//	for(i=0;i<n;i++) printf("%d ",a[i]);
//	printf("\n");
	if(n%2!=0){
//		printf("<1>,");
		for(i=n-1;i>-1;i--) printf("%d ",a[i]);
	}
	else{
//		printf("<2>,");
		for(i=0;i<n;i++) printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}