#include<stdio.h>
int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		int sum=0;
		sum=a*100+b*10+c*1;
		if(sum%4==0)
		printf("YES\n");
		else
		printf("NO\n");	
		
	}
	return 0;
}