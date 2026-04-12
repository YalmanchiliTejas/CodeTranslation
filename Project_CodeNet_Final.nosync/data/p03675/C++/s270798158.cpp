#include<stdio.h>
int n;
int a[200000];
int ans[200000],b,c,i;


int main(void){

	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	b = 0;
	c = n-1;
	for(i=0;i<n;i++){
		if(i%2==0){
			ans[b] = a[n-1-i];
			b++;
		}else{
			ans[c] = a[n-1-i];
			c--;
		}
	}

	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
