#include<stdio.h>
int main(void)
{
	int n[13],a[101],i,j,flg,cnt;
	for(i=1;i<=100;i++) a[i]=0;
	for(i=1;i<=12;i++) scanf("%d",&n[i]);
	cnt=0;
	for(i=1;i<=100;i++){
		for(j=1;j<=12;j++){
			if(i==n[j]) cnt++;
		}
		a[i]=cnt;
	}
	flg=0;
	for(i=1;i<=100;i++){
		if(a[i]%2!=0) flg=1;
	}
	if(flg!=0) printf("no\n");
	else printf("yes\n");
	return 0;
}	