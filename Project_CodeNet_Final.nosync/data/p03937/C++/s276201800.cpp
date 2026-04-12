#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,m,en[101];
char s[100][100];
int main()
{
	re(n),re(m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	en[0]=1;
	for(int i=1;i<=n;++i)
	{
		en[i]=en[i-1];
		for(int j=1;j<en[i];++j)if(s[i][j]=='#')return puts("Impossible"),0;
		if(s[i][en[i]]!='#')return puts("Impossible"),0;
		while(s[i][en[i]+1]=='#')++en[i];
		for(int j=en[i]+1;j<=m;++j)if(s[i][j]=='#')return puts("Impossible"),0;
	}
	puts("Possible");
}