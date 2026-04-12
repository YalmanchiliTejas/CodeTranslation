#include<stdio.h>
#include<string.h>
int main (void){
	int r,g,b,n;
	while(scanf("%d%d%d",&r,&g,&b)!=EOF){
		n=r*100 + g*10 +b;
		if(n%4==0){
			printf("YES");}
		else printf("NO");
	}
	return 0;
}
