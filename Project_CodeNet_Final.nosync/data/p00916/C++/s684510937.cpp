#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 302;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int flag[MAX_N][MAX_N],n;

void dfs(int u,int v)
{
	flag[u][v] = 1;
	rep(i,4){
		int nx = u + dx[i];
		int ny = v + dy[i];
		if(nx >= 0 && nx < 300 && ny >= 0 && ny < 300){
			if(flag[nx][ny] == 0){
				dfs(nx,ny);
			}
		}
	}
	return;
}

int main()
{
	while(1){
		scanf("%d",&n);
		if(n == 0){
			break;
		}
		vector<double> x,y;
		vector<int> bx,by;
		rep(i,300){
			rep(j,300){
				flag[i][j] = 0;
			}
		}
		rep(i,n){
			int s,t,u,v;
			scanf("%d%d%d%d",&s,&t,&u,&v);
			x.push_back(s),x.push_back(s-0.5),x.push_back(s+0.5);
			x.push_back(u),x.push_back(u-0.5),x.push_back(u+0.5);
			bx.push_back(s),bx.push_back(u);
			y.push_back(t),y.push_back(t-0.5),y.push_back(t+0.5);
			y.push_back(v),y.push_back(v-0.5),y.push_back(v+0.5);
			by.push_back(t),by.push_back(v);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		x.erase(unique(x.begin(),x.end()),x.end());
		y.erase(unique(y.begin(),y.end()),y.end());
		for(int i=0;i<n*2;i+=2){
			bx[i] = lower_bound(x.begin(),x.end(),(double)bx[i]) - x.begin();
			bx[i+1] = lower_bound(x.begin(),x.end(),(double)bx[i+1]) - x.begin();
			by[i] = lower_bound(y.begin(),y.end(),(double)by[i]) - y.begin();
			by[i+1] = lower_bound(y.begin(),y.end(),(double)by[i+1]) - y.begin();
			for(int j=bx[i];j<=bx[i+1];j++){
				flag[j][by[i]] = 1;
				flag[j][by[i+1]] = 1;
			}
			for(int j=by[i+1];j<=by[i];j++){
				flag[bx[i]][j] = 1;
				flag[bx[i+1]][j] = 1;
			}
		}
		int cnt = 0;
		rep(i,300){
			rep(j,300){
				if(flag[i][j] == 0){
					cnt++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}