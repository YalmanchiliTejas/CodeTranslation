#include <stdio.h>
int main(int argc, char *argv[])
{
	int a,b,c,n;
	scanf("%d %d %d",&a,&b,&c);
	n=a*100+b*10+c;
	if(n%4==0)printf("YES");
	else printf("NO");
	return 0;
}