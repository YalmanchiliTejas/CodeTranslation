#include<stdio.h>
int a[6],t;
#define f(A,B,C,D) (t=a[D],a[D]=a[C],a[C]=a[B],a[B]=a[A],a[A]=t)
int main(void)
{
	int n,r,i;
	char s[9];
	while(scanf("%d",&n),n)
	{
		for(r=i=1;i<7;++i)a[i-1]=i;
		while(n--)
		{
			scanf("%s",s);
			if(s[0]=='N')f(0,4,5,1);
			if(s[0]=='S')f(0,1,5,4);
			if(s[0]=='E')f(0,2,5,3);
			if(s[0]=='W')f(0,3,5,2);
			if(s[0]=='R')f(1,3,4,2);
			if(s[0]=='L')f(1,2,4,3);
			r+=a[0];
		}
		printf("%d\n",r);
	}
	return 0;
}