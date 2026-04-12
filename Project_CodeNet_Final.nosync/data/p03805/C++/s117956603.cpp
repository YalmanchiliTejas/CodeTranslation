#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m;
vector<int> G[9];
int ans=0;
int bit=0;

void dfs(int v){
	bit+=1<<v;
	if(bit+1==1<<n){
		ans++;
	}
	for(int i=0;i<G[v].size();i++){
		if(!(bit>>G[v][i] & 1)){
			dfs(G[v][i]);
		}
	}
	bit-=1<<v;
}

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0);
	printf("%d\n",ans);
	return 0;
}