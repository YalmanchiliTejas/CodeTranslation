#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 10005

struct Edge{
	Edge(int arg_to,int arg_weight){
		to = arg_to;
		weight = arg_weight;
	}

	int to,weight;
};

struct Info{
	Info(int arg_dist,int arg_node_id){
		dist = arg_dist;
		node_id = arg_node_id;
	}
	bool operator<(const struct Info &arg) const{

		return dist > arg.dist; //距離の降順
	}

	int dist,node_id;
};


int V;
int max_dist[SIZE];
vector<Edge> G[SIZE];
vector<Info> info[SIZE];


void dfs(int node_id,int pre){

	int tmp_max = 0;

	for(int i = 0; i < G[node_id].size(); i++){

		int child = G[node_id][i].to;
		if(child == pre)continue;

		dfs(child,node_id);

		info[node_id].push_back(Info(max_dist[child]+G[node_id][i].weight,child));
		tmp_max = max(tmp_max,max_dist[child]+G[node_id][i].weight);
	}
	max_dist[node_id] = tmp_max;
}

void dfs2(int node_id,int pre){

	for(int i = 0; i < G[node_id].size(); i++){

		if(G[node_id][i].to == pre){

			if(info[pre][0].node_id == node_id){ //親の最大距離方向が自分である場合

				if(info[pre].size() == 1){ //子が自分のみ

					info[node_id].push_back(Info(G[node_id][i].weight,pre));

				}else{

					info[node_id].push_back(Info(info[pre][1].dist+G[node_id][i].weight,pre));
				}

			}else{ //親の最大距離方向が自分ではない場合

				info[node_id].push_back(Info(info[pre][0].dist+G[node_id][i].weight,pre));
			}
			break;
		}
	}
	//親を先に処理
	sort(info[node_id].begin(),info[node_id].end());
	max_dist[node_id] = info[node_id][0].dist;

	for(int i = 0; i < G[node_id].size(); i++){

		int child = G[node_id][i].to;
		if(child == pre)continue;

		dfs2(child,node_id);
	}
}

int main(){

	scanf("%d",&V);

	if(V == 1){

		printf("0\n");
		return 0;
	}

	int from,to,weight;

	for(int i = 0; i < V-1; i++){

		scanf("%d %d %d",&from,&to,&weight);

		G[from].push_back(Edge(to,weight));
		G[to].push_back(Edge(from,weight));
	}

	dfs(0,-1);
	dfs2(0,-1);

	for(int i = 0; i < V; i++){

		printf("%d\n",max_dist[i]);
	}

	return 0;
}

