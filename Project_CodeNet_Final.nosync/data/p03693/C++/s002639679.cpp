#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s,d,f,g,h,j,i;
	scanf("%d %d %d",&a,&s,&d);
	f=a*100+s*10+d;
	if(f%4==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}