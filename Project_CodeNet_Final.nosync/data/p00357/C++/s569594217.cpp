#include<stdio.h>
int main(void)
{
	int n,flg,i,max;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)  scanf("%d",&a[i]);
	flg=0; max=1;
	for(i=0;i<n;i++){
		max--; a[i]=a[i]/10;
		if(max<=a[i]) max=a[i];
		if(max==0){
			flg=1; break;
		}
	}
	max=0;
	if(flg==0){
		for(i=n-1;i>=0;i--){
			if(max<=a[i]) max=a[i];
			if(max==0){
				flg=1; break;
			}
			max--;
		}
	}
	if(flg==0) printf("yes\n");
	else printf("no\n");
	return 0;
	}
