#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
int main()
{
    int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if((a*100+b*10+c)%4==0)
		printf("YES\n");
	else
		printf("NO\n");	
	
	
    return 0;
 }