#include<cstdio>
using namespace std;
int n,m,cnt=-1;
char a[10][10];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);int na=1,nb=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(a[i][j]=='#') ++cnt;
	while(na!=n||nb!=m) {
		if(a[na][nb+1]=='#') {++nb;--cnt;}
		else if(a[na+1][nb]=='#') {++na;--cnt;}
		else {printf("Impossible\n");return 0;}
	}
	if(!cnt) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}