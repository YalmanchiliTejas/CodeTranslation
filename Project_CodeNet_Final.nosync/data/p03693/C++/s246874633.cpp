#include<stdio.h>
#include<string.h>
int main(void)
{
    int a,b,c,w=0;
	scanf("%d %d %d",&a,&b,&c);
	w=w+a*100+b*10+c;
	if(w%4==0) printf("YES\n");
	else if(w%4!=0) printf("NO\n");
	return 0;
}