#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-10;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
vector<int>g[110000];
int dist[110000];
int ans;
int dfs(int a,int b){
	int rem=0;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		int q=dfs(g[a][i],a);
		rem+=q;
	}
	if(rem>1)ans=1;
	if(rem==1)return 0;
	return 1;
}
int main(){
	int a;scanf("%d",&a);
	if(a==2){
		printf("Second\n");return 0;
	}
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	int t=0;
	for(int i=0;i<a;i++)if(g[i].size()>1)t=i;
	dfs(t,-1);
	if(ans)printf("First\n");
	else printf("Second\n");
}