#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl;
int r,c,m,per[50][50],on[50][50],off[50][50],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dir[50][50][50][50];
string mp[50];
bool inn(int x,int y) { return (0<=x&&x<r&&0<=y&&y<c); }
void dfs(int sx,int sy,int x,int y,int px,int py,int id){
	dir[sx][sy][x][y]=id;
	rep(i,4){
		int nx=x+dx[i],ny=y+dy[i];
		if(!(nx==px && ny==py)&&inn(nx,ny)&&mp[nx][ny]=='.') dfs(sx,sy,nx,ny,x,y,id);
	}
}
int before[50][50];
int main(){
	cin>>r>>c>>m;
	rep(i,r) cin>>mp[i];
	rep(i,r) rep(j,c) cin>>per[i][j];
	rep(i,r) rep(j,c) cin>>on[i][j];
	rep(i,r) rep(j,c) cin>>off[i][j];
	rep(i,r) rep(j,c) if(mp[i][j]=='.'){
		rep(k,4){
			int ni=i+dx[k],nj=j+dy[k];
			if(inn(ni,nj)&&mp[ni][nj]=='.') dfs(i,j,ni,nj,i,j,k);
		}
	}
	int a,b,x,y;
	cin>>a>>b;
	int ans=0,t=0;
	rep(i,m-1){
		cin>>x>>y;
		while(!(a==x&&b==y)){
			t++;
			if(before[a][b]==0) ans+=on[a][b];
			else {
				ans+=min((t-before[a][b])*per[a][b],off[a][b]+on[a][b]);
			}
			int d=dir[a][b][x][y];
			before[a][b]=t;
			a+=dx[d],b+=dy[d];
		}
	}
	t++;
	if(before[a][b]==0) ans+=on[a][b];
	else {
		ans+=min((t-before[a][b])*per[a][b],off[a][b]+on[a][b]);
	}
	before[a][b]=t;
	rep(i,r) rep(j,c) if(before[i][j]>0) ans+=off[i][j];
	cout << ans<< endl;
}