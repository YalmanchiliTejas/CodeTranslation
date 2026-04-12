#include<cstdio>
#include<cstdlib>
#define MAXN 10
#define LL long long
int h,w;
char mp[MAXN][MAXN];
bool b[MAXN][MAXN];
const int dx[]={1,0},dy[]={0,1};//1 3
int cnt=0,ans=1/*起点*/;
void dfs(int x,int y)
{
	for(int i=0;i<2;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>0&&nx<=h&&ny>0&&ny<=w&&!b[nx][ny]&&mp[nx][ny]=='#')
		{
			b[nx][ny]=1;
			dfs(nx,ny);
			b[nx][ny]=0;
			ans++;
			break;//能往下走就往下走，否则才往右走，这里是要找到一条路，否则它会把其它路的答案算进来
		}
	}
}
int main()
{
	scanf("%d %d",&h,&w);
	for(int i=1;i<=h;i++)
	{
		scanf("%s",mp[i]+1);
		for(int j=1;j<=w;j++)
			if(mp[i][j]=='#') cnt++;
	}
	b[1][1]=1;
	dfs(1,1);
	if(ans==cnt) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}