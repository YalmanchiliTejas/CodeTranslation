#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,a,b;
int d[11][11];
vector<P> G[3][205];
int f[105][105];
int dp[205];

int dijk(int ac,int bc){
	for(int i=0;i<202;i++){
		dp[i]=INF;
	}
	dp[0]=0;
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,0));
	while(que.size()){
		P q=que.top();
		que.pop();
		int v=q.second;
		if(q.first>dp[v])continue;
		for(int i=0;i<3;i++){
			for(int j=0;j<G[i][v].size();j++){
				int co=G[i][v][j].second;
				if(i==1)co=ac;
				if(i==2)co=bc;
				if(co+q.first<dp[G[i][v][j].first]){
					dp[G[i][v][j].first]=co+q.first;
					que.push(P(co+q.first,G[i][v][j].first));
				}
			}
		}
	}
	//printf("%d %d %d\n",ac,bc,dp[201]);
	return dp[201];
}

int main(void){
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			scanf("%d",&d[i][j]);
		}
	}
	for(int i=0;i<100;i++){
		G[1][i].push_back(P(i+1,-1));
	}
	for(int i=101;i<201;i++){
		G[2][i].push_back(P(i+1,-1));
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int k=0;k<a;k++){
				for(int l=0;l<b;l++){
					f[i][j]=max(f[i][j],d[k][l]-(k+1)*i-(l+1)*j);
				}
			}
			G[0][i].push_back(P(201-j,f[i][j]));
		}
	}
	bool flag=true;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(dijk(i+1,j+1)!=d[i][j])flag=false;
		}
	}
	if(flag){
		printf("Possible\n");
		int siz=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<202;j++){
				siz+=G[i][j].size();
			}
		}
		printf("%d %d\n",202,siz);
		for(int i=0;i<3;i++){
			for(int j=0;j<202;j++){
				for(int k=0;k<G[i][j].size();k++){
					if(i==0){
						printf("%d %d %d\n",j+1,G[i][j][k].first+1,G[i][j][k].second);
					}else if(i==1){
						printf("%d %d X\n",j+1,G[i][j][k].first+1);
					}else{
						printf("%d %d Y\n",j+1,G[i][j][k].first+1);
					}
				}
			}
		}
		printf("%d %d\n",1,202);
	}else{
		printf("Impossible\n");
	}
	return 0;
}