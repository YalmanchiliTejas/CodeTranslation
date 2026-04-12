#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int r,c,m;
int fie[51][51];
ll data[51][51][3];
int x[1001],y[1001];
bool used[51][51];
int px[51][51],py[51][51];
ll on[51][51];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int x,int y){
	used[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0 && nx<c && ny>=0 && ny<r){
			if(fie[nx][ny]==0 && !used[nx][ny]){
				px[nx][ny]=x;
				py[nx][ny]=y;
				dfs(nx,ny);
			}
		}
	}
}

int main(void){
	scanf("%d %d %d",&r,&c,&m);
	for(int i=0;i<r;i++){
		string str;
		cin >> str;
		for(int j=0;j<c;j++){
			if(str[j]=='.')fie[j][i]=0;
			else fie[j][i]=-1;
		}
	}
	for(int k=0;k<3;k++){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				scanf("%d",&data[j][i][k]);
			}
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&y[i],&x[i]);
	}
	vector<P> route;
	route.push_back(P(x[0],y[0]));
	for(int i=1;i<m;i++){
		memset(used,false,sizeof(used));
		dfs(x[i-1],y[i-1]);
		vector<P> go;
		P p=P(x[i],y[i]);
		while(p.first!=x[i-1] || p.second!=y[i-1]){
			go.push_back(p);
			P np;
			np.first=px[p.first][p.second];
			np.second=py[p.first][p.second];
			p=np;
		}
		reverse(go.begin(),go.end());
		for(int i=0;i<go.size();i++){
			route.push_back(go[i]);
		}
	}
	ll res=0;
	memset(on,-1,sizeof(on));
	for(int i=0;i<route.size();i++){
		int nx=route[i].first,ny=route[i].second;
		if(on[nx][ny]==-1){
			res+=data[nx][ny][1];
			on[nx][ny]=i;
		}else{
			res+=min(data[nx][ny][1]+data[nx][ny][2],data[nx][ny][0]*(ll)(i-on[nx][ny]));
			on[nx][ny]=i;
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(on[j][i]!=-1)res+=data[j][i][2];
		}
	}
	printf("%lld\n",res);
	return 0;
}