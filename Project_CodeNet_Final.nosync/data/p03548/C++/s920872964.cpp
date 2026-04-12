#include<stdio.h>
int main(){
	int x,y,z,ans;
	scanf("%d%d%d",&x,&y,&z);
	ans=x/(z+y);
	if(x-ans*(z+y)>=z)
		printf("%d\n",ans);
	else
		printf("%d\n",ans-1);
	return 0;
}