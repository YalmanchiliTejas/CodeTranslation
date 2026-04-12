#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define INF 0x3f3f3f3f
#define umx(i,j) ((i)=max(i,j))
int n,a[N*3],dp2,dp1[N],dp[N][N],add=0;
inline void upd(int i,int j,int v){
	umx(dp[i][j],v);umx(dp[j][i],v);
	umx(dp1[i],v);umx(dp1[j],v);
	umx(dp2,v);
}
struct Node{
	int i,j,v;
	inline Node(int ii,int jj,int vv){i=ii;j=jj;v=vv;}
};
vector<Node> gx;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3*n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) dp[i][j]=-INF;
		dp1[i]=-INF;
	}
	dp2=0;
	dp1[a[1]]=0;dp1[a[2]]=0;
	dp[a[1]][a[2]]=0;dp[a[2]][a[1]]=0;
	for(int i=1;i<n;++i){
		sort(a+3*i,a+3*i+3);
		if(a[3*i]==a[3*i+2]){++add;continue;}
		gx.push_back(Node(a[3*i+1],a[3*i+2],max(dp2,dp[a[3*i]][a[3*i]]+1)));
		gx.push_back(Node(a[3*i],a[3*i+2],max(dp2,dp[a[3*i+1]][a[3*i+1]]+1)));
		gx.push_back(Node(a[3*i],a[3*i+1],max(dp2,dp[a[3*i+2]][a[3*i+2]]+1)));
		for(int j=1;j<=n;++j){
			gx.push_back(Node(j,a[3*i],max(dp1[j],dp[j][a[3*i+1]]+(a[3*i+1]==a[3*i+2]))));
			gx.push_back(Node(j,a[3*i+1],dp1[j]));
			gx.push_back(Node(j,a[3*i+2],max(dp1[j],dp[j][a[3*i+1]]+(a[3*i+1]==a[3*i]))));
		}
		for(int j=0;j<gx.size();++j) upd(gx[j].i,gx[j].j,gx[j].v);
		gx.clear();
	}
	++dp[a[3*n]][a[3*n]];
	umx(dp1[a[3*n]],dp[a[3*n]][a[3*n]]);
	umx(dp2,dp1[a[3*n]]);
	printf("%d\n",dp2+add);
	return 0;
}