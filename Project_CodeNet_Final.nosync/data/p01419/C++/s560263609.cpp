#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long On[55][55],Off[55][55],Con[55][55];
int R,C,M;
char G[55][55];
long long T[55][55],res,cT;
int move[4][2]={-1,0,0,1,1,0,0,-1};
bool vst[55][55];
pair <int,int> Task[1005];

bool in(int r,int c)
{
	if(r<0||c<0||r>=R||c>=C)
		return false;
	return true;
}

void update(int x,int y,long long t)
{
	if(!T[x][y]) res+=On[x][y];
	else res+=min(On[x][y]+Off[x][y],Con[x][y]*(t-T[x][y]));
	T[x][y]=t;
}

bool dfs(int cX,int cY,int eX,int eY,long long t)
{
	vst[cX][cY]=true;
	if(cX==eX&&cY==eY)
	{
		cT=t;
		return true;
	}
	for(int i=0;i<4;i++)
	{
		int nX=cX+move[i][0],nY=cY+move[i][1];
		if(!in(nX,nY)) continue;
		if(G[nX][nY]=='#') continue;
		if(vst[nX][nY]) continue;
		if(dfs(nX,nY,eX,eY,t+1))
		{
			update(cX,cY,t);
			return true;
		}
	}
	return false;
}

void solve()
{
	memset(T,0,sizeof(T));
	cT=1,res=0;
	for(int i=0;i<M-1;i++)
	{
		memset(vst,0,sizeof(vst));
		dfs(Task[i].first,Task[i].second,Task[i+1].first,Task[i+1].second,cT);
	}
	update(Task[M-1].first,Task[M-1].second,cT);
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			if(T[i][j]>0) res+=Off[i][j];
}

int main()
{
	while(scanf("%d%d%d",&R,&C,&M)!=EOF)
	{
		for(int i=0;i<R;i++) scanf("%s",G[i]);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				scanf("%lld",&Con[i][j]);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				scanf("%lld",&On[i][j]);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				scanf("%lld",&Off[i][j]);
		for(int i=0;i<M;i++) scanf("%d%d",&Task[i].first,&Task[i].second);
		solve();
		printf("%lld\n",res);
	}
	return 0;
}