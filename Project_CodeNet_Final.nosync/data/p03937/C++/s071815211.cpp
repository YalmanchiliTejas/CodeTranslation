#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define pb push_back
#define debug(x) cerr<<#x<<"="<<x<<endl;
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
int n,m,cnt,x,y;char s[10][10];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#') cnt++;
	if(cnt!=n+m-1) return puts("Impossible"),0;
	
	x=1;y=1;
	while(!(x==n&&y==m))
	{
		if((s[x+1][y]=='#')+(s[x][y+1]=='#')!=1)
			return puts("Impossible"),0;
		if(s[x+1][y]=='#') x++;
		else y++;
	}
	puts("Possible");
	return 0;
}