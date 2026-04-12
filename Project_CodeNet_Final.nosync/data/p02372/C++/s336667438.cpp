// 参考:http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4325944#1

#include<bits/stdc++.h>
using namespace std;

#define MAX 10001

struct Edge{
	Edge(int to,int weight){
		this->to = to;
		this->weight = weight;
	}
	int to,weight;
};

int N;
vector<int> Dp[MAX];
int Height[MAX] = {0};
vector<Edge> G[MAX];

int dfs(int node,int edge_index){
	if(Dp[node][edge_index] >= 0){
		return Dp[node][edge_index];
	}
	Dp[node][edge_index] = G[node][edge_index].weight;
	int to = G[node][edge_index].to;

	for(int i = 0; i < G[to].size(); i++){
		int next = G[to][i].to;
		if(next == node)continue;

		Dp[node][edge_index] = max(Dp[node][edge_index],dfs(to,i)+G[node][edge_index].weight);
	}
	return Dp[node][edge_index];
}

void getHeight(){
	for(int i = 0; i < N; i++){
		for(int j = 0;j < G[i].size();++j){
			if(Dp[i][j] >= 0)continue;
			Dp[i][j] = dfs(i,j);
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < G[i].size();++j){
			Height[i] = max(Height[i],Dp[i][j]);
		}
	}
}

int main(){
	scanf("%d",&N);
	int from,to,weight;
	
	for(int i = 0;i < N - 1;++i){
		scanf("%d %d %d",&from,&to,&weight);
		G[from].push_back(Edge(to,weight));
		G[to].push_back(Edge(from,weight));
	}

	for(int i = 0; i < N;++i){
		for(int j = 0;j < G[i].size();++j){
			Dp[i].push_back(-1);
		}
	}
	getHeight();
	for(int i = 0; i < N;++i){
		printf("%d\n",Height[i]);
	}
}
