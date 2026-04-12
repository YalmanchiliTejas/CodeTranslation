#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[99];
	int m,n,i,a,b,c;
	while(scanf("%d%d",&m,&n),m)
	{
		bool dead[1000]={0};
		for(a=0,c=i=1;i<=n;++i)
		{
			scanf("%s",s);
			if(c < m)
			{
				b=0;
				if(i%15==0)
				{
					if(strcmp(s,"FizzBuzz"))b=1;
				}
				else if(i%5==0)
				{
					if(strcmp(s,"Buzz"))b=1;
				}
				else if(i%3==0)
				{
					if(strcmp(s,"Fizz"))b=1;
				}
				else if(i != atoi(s)) b=1;

				if(b)
					dead[a]=1, ++c;

				do
				{
					a = (a+1)%m;
				}while(dead[a]);
			}
		}
		for(b=i=0;i<m;++i) if(!dead[i]) printf("%s%d", b++?" ":"", i+1);
		puts("");
	}
	return 0;
}