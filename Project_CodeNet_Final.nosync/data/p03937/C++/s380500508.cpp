#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}

	inline int tc()
	{
		int c=fetch();
		while(c<=32 && c!=EOF)c=fetch();
		return c;
	}
}
using ae86::ty;
using ae86::tc;

const int _ = 9;

int H,W,val[_][_]={0};

int main()
{
	H=ty(),W=ty();
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			val[i][j]=tc()=='#';

	for(int x=1,y=1;x!=H || y!=W;)
	{
		if(val[x][y]!=1){puts("Impossible");return 0;}
		val[x][y]=2;
		if(val[x+1][y])x++;
		else if(val[x][y+1])y++;
		else{puts("Impossible");return 0;}
	}
	if(val[H][W]!=1){puts("Impossible");return 0;}
	val[H][W]=2;

	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			if(val[i][j]==1){puts("Impossible");return 0;}
	puts("Possible");

	return 0;
}
