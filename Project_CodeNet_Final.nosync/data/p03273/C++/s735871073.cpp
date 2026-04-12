#include<bits/stdc++.h>
using namespace std;
#define RI register int
int n,m,bx[105],by[105];
char mp[105][105];
int main()
{
	scanf("%d%d",&n,&m);
	for(RI i=1;i<=n;++i) scanf("%s",mp[i]+1);
	for(RI i=1;i<=n;++i) {
		int flag=1;
		for(RI j=1;j<=m;++j) if(mp[i][j]=='#') {flag=0;break;}
		if(flag) bx[i]=1;
	}
	for(RI j=1;j<=m;++j) {
		int flag=1;
		for(RI i=1;i<=n;++i) if(mp[i][j]=='#') {flag=0;break;}
		if(flag) by[j]=1;
	}
	for(RI i=1;i<=n;++i) {
		if(bx[i]) continue;
		for(RI j=1;j<=m;++j)
			if(!by[j]) putchar(mp[i][j]);
		puts("");
	}
	return 0;
}