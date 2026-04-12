#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<time.h>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<ext/rope>
#define ll long long
#define oo 0x7fffffff
using namespace std;
using namespace __gnu_cxx;
inline int read()
{
	int out=0,fh=1;
	char cc=getchar();
	while ((cc>'9'||cc<'0')&&cc!='-')
		cc=getchar();
	if (cc=='-')
		{
			fh=-1;
			cc=getchar();
		}
	while (cc>='0'&&cc<='9')
		{
			out=out*10+cc-'0';
			cc=getchar();
		}
	return out*fh;
}
int h,w;
int avr[101],avc[101];
char mm[101][101];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	h=read(),w=read();
	int lastrow;
	for(int i=1;i<=h;++i)
		scanf("%s",mm[i]+1);
	for(int i=1;i<=h;++i)
		for(int j=1;j<=w;++j)
			{
				char buf;
				buf=mm[i][j];
				if(buf=='#')
					avr[i]=avc[j]=1;
			}
	for(int i=h;i>=1;--i)
		if(avr[i])
			{
				lastrow=i;
				break;
			}
	for(int i=1;i<=h;++i)
		{
			if(!avr[i])
				continue;
			for(int j=1;j<=w;++j)
				{
					if(!avc[j])
						continue;
					printf("%c",mm[i][j]);
				}
			if(i!=lastrow)
				printf("\n");
		}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
