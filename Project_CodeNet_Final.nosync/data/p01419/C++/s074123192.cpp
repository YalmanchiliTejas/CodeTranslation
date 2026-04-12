#include<iostream>
#include<vector>
using namespace std;
int h,w,m;
int t[50][50];
int con[50][50],on[50][50],off[50][50];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int to[1000][50][50];
string s[50];
void dfs(int x,int y,int pr,int id)
{
	for(int dr=0;dr<4;dr++)
	{
		if(pr>=0&&(dr-pr+4)%4==2)
		{
			to[id][x][y]=dr;
			continue;
		}
		int tx=x+dx[dr],ty=y+dy[dr];
		if(tx>=0&&ty>=0&&tx<h&&ty<w&&s[tx][ty]!='#')dfs(tx,ty,dr,id);
	}
}
main()
{
	cin>>h>>w>>m;
	for(int i=0;i<h;i++)cin>>s[i];
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>con[i][j];
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>on[i][j];
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>off[i][j];
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)t[i][j]=-1;
	for(int i=0;i<m;i++)for(int k=0;k<h;k++)for(int l=0;l<w;l++)to[i][k][l]=-1;
	vector<pair<int,int> >xy;
	for(int i=0;i<m;i++)
	{
		int x,y;cin>>x>>y;xy.push_back({x,y});
		dfs(x,y,-1,i);
	}
	int nx=xy[0].first,ny=xy[0].second;
	t[nx][ny]=0;
	int ans=on[nx][ny]+off[nx][ny];
	int nowt=0;
	for(int i=1;i<m;i++)
	{
		int tx=xy[i].first,ty=xy[i].second;
		while(nx!=tx||ny!=ty)
		{
			int r=to[i][nx][ny];
			nx+=dx[r],ny+=dy[r];
			nowt++;
			ans+=on[nx][ny]+off[nx][ny];
			if(t[nx][ny]>=0)
			{
				int A=on[nx][ny]+off[nx][ny];
				int B=(nowt-t[nx][ny])*con[nx][ny];
				if(A>B)ans-=A-B;
			}
			t[nx][ny]=nowt;
		}
	}
	cout<<ans<<endl;
}

