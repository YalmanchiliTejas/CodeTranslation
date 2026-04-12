#include<stdio.h>
#include<string.h>
int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
		int ans;
		ans=r*100+g*10+b;
		if(ans%4==0)
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
} 