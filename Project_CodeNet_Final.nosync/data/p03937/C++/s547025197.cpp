#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,t) for(int i = s; i <= t; ++ i)
#define fi first
#define se second
#define mp make_pair
const int dx[] = {0,1};
const int dy[] = {1,0};
char mat[9][9];
int n, m;
queue<pair<int,int> > Q;
bool vis[9][9];

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",mat[i]+1);
	if(mat[1][1] != '#') {puts("Impossible"); return 0;}
	Q.push(mp(1,1));
	pair<int,int> h, nx; 
	while(!Q.empty())
	{
		h = Q.front(); Q.pop();
		if(vis[h.fi][h.se]) continue;
		vis[h.fi][h.se] = true;
		rep(i,0,1)
		{
			nx.fi = h.fi+dx[i];
			nx.se = h.se+dy[i];
			if(nx.fi < 1 || nx.se < 1 || nx.fi > n || nx.se > m) continue;
			if(mat[nx.fi][nx.se] != '#') continue;
			Q.push(nx);
			break;
		}
	}
	rep(i,1,n) rep(j,1,m) if(mat[i][j] == '#' && vis[i][j] == false) {puts("Impossible"); return 0;}
	rep(i,1,n) rep(j,1,m) if(mat[i][j] == '.' && vis[i][j] == true) {puts("Impossible"); return 0;}
	puts("Possible");
	return 0;
}
