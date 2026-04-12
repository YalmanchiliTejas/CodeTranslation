#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする

struct edge{int to,cost;};
vector<int> G[100005];

 
ll n,m,ans=0;
int i,j;
ll dp[12][12];
int a,b;
bool vis[12];

void dfs(int x){
	vis[x] = true;
	int count=0;
	for(i=1;i<=n;i++){
		if(vis[i])
		count++;
	}
	if(count==n){
		ans += 1;
	}else{
		for(int i=1;i<=n;i++){
			if(dp[x][i] && !vis[i]){
				dfs(i);
			}
		}
	}
	vis[x]=false;
	return;
}


int main(){
	cin>>n>>m;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			dp[i][j]=0;
		}
	}
	for(i=0;i<m;i++){
		cin>>a>>b;
		dp[a][b]=dp[b][a]=1;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}