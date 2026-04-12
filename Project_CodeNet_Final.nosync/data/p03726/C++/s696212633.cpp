#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;

const int MAX_N=1e5;

int N;
vector<int> G[MAX_N+1];

set<int> leaf;
int dp[MAX_N];

int dfs(int v,int p){
	if (v==N){
		return 1;
	}
	if (dp[v]!=-1){
		return dp[v];
	}
	if (leaf.find(v)!=leaf.end()){
		return dp[v]=0;
	}
	int c=0;
	REP(i,(int)G[v].size()){
		if (G[v][i]!=p){
			if (!dfs(G[v][i],v)){
				c++;
			}
		}
	}
	if (c>=2 || c==0){
		return dp[v]=0;
	}
	int flg=1;
	REP(i,(int)G[v].size()){
		if (G[v][i]!=p){
			if (!dp[G[v][i]]){
				int v2=G[v][i];
				REP(j,(int)G[v2].size()){
					if (G[v2][j]!=v){
						if (!dfs(G[v2][j],v2)){
							flg=0;
						}
					}
				}
			}
		}
	}
	return dp[v]=flg;
}

int main(){
	cin>>N;
	fill(dp,dp+N,-1);
	REP(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	FOR(i,1,N){
		if (G[i].size()==1){
			leaf.insert(i);
			G[i].push_back(N);
		}
	}
	if (dfs(0,-1)){
		cout<<"Second"<<endl;
	}else{
		cout<<"First"<<endl;
	}
	return 0;
}
