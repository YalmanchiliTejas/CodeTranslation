#include<stdio.h>
int main(void)
{
	int a[6],s[6],d,f,g,h,i,j;
	while(1){
		scanf("%d %d",&a[0],&s[0]);
		f=a[0]+s[0];
		g=0;
		if(a[0]==0&&s[0]==0) break;
		for(i=1;i<5;i++){
			scanf("%d %d",&a[i],&s[i]);
			d=a[i]+s[i];
			if(f<d){
				f=d;
				g=i;
			}
		}
		if(g==0) printf("A ");
		if(g==1) printf("B ");
		if(g==2) printf("C ");
		if(g==3) printf("D ");
		if(g==4) printf("E ");
		printf("%d\n",f);
	}
	return 0;
}