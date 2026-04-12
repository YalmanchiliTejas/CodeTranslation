#include<stdio.h>
#include<string.h>
int F(char c){return !strchr("yuiophjklnm",c);}
int main()
{
	char s[64];
	int i,r,f,g;
	while(scanf("%s",s),*s-'#')
	{
		f=F(*s);
		for(i=r=0;s[++i];)
		{
			g=F(s[i]);
			r+=f!=g;
			f=g;
		}
		printf("%d\n",r);
	}
	return 0;
}