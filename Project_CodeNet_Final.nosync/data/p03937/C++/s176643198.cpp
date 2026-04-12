#include <cstdio>

using namespace std;

char a[10][10];
bool v[10][10];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	int x=1,y=1;
	while (x<n||y<m)
	{
		v[x][y]=1;
		if (x<n&&a[x+1][y]=='#'&&y<m&&a[x][y+1]=='#') {puts("Impossible");return 0;}
		if ((x==n||a[x+1][y]=='.')&&(y==m||a[x][y+1]=='.')) {puts("Impossible");return 0;}
		if (x<n&&a[x+1][y]=='#') x++; else y++;
	}
	v[n][m]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]=='#'&&!v[i][j]) {puts("Impossible");return 0;}
	puts("Possible");
	return 0;
}
