#include<bits/stdc++.h>
#define LL long long
#define int LL
const LL inf=0x3f3f3f3f;
using namespace std;
template<typename tp> inline void read(tp &x)
{
	x=0; char c=getchar(); bool f=0;
	for(;c<'0'||c>'9';f|=(c=='-'),c = getchar());
	for(;c>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0',c = getchar());
	if(f) x=-x;
}
int vis[110][2];
int n,m;
char s[110];
char M[110][110];
signed main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			if(s[j]=='#')
				M[i][j]=1,vis[i][1]=vis[j][2]=1;
	}
	for(int i=1;i<=n;i++)
		if(vis[i][1])
		{
			for(int j=1;j<=m;j++)
				if(vis[j][2])
				{
					if(M[i][j]) printf("#");
					else printf(".");
				}
			puts("");
		}
	return 0;
}