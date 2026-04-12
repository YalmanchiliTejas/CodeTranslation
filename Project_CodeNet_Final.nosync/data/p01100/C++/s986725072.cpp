#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 6000

struct Info{
	int A,B;
};


struct Edge{
	Edge(int arg_to,int arg_capacity,int arg_rev_index){
		to = arg_to;
		capacity = arg_capacity;
		rev_index = arg_rev_index;
	}
	int to,capacity,rev_index;
};

int N,M;
int human_index[100],info_index[5050];
Info info[5050];


int V,E;
vector<Edge> G[NUM];
bool used[NUM];

void add_edge(int from,int to,int capacity){
	G[from].push_back(Edge(to,capacity,G[to].size()));
	G[to].push_back(Edge(from,0,G[from].size()-1));
}

int dfs(int node_id,int sink,int flow){
	if(node_id == sink)return flow;
	used[node_id] = true;

	for(int i = 0; i < G[node_id].size(); i++){
		Edge &e = G[node_id][i];
		if(used[e.to] == false && e.capacity > 0){
			int tmp_flow = dfs(e.to,sink,min(flow,e.capacity));
			if(tmp_flow > 0){
				e.capacity -= tmp_flow;
				G[e.to][e.rev_index].capacity += tmp_flow;
				return tmp_flow;
			}
		}
	}
	return 0;
}


int max_flow(int source,int sink){ //source:始点 sink:終点
	int flow = 0,add;
	while(true){ //増加パスが存在する限り、流量を追加し続ける
		for(int i = 0; i < V; i++)used[i] = false;
		add = dfs(source,sink,BIG_NUM);
		if(add == 0)break;
		flow += add;
	}
	return flow;
}

void delete_graph(){

	for(int i = 0; i < NUM; i++)G[i].clear();
}


void func(){

	for(int i = 0; i < M; i++){
		scanf("%d %d",&info[i].A,&info[i].B);
		info[i].A--;
		info[i].B--;
	}

	delete_graph();

	int min_max;
	int source = 0,sink = 1,index = 2;

	for(int i = 0; i < N; i++)human_index[i] = index++;
	for(int i = 0; i < M; i++)info_index[i] = index++;
	V = index;

	for(int i = 0; i < N; i++){
		add_edge(source,human_index[i],0);
	}

	for(int i = 0; i < M; i++){
		add_edge(human_index[info[i].A],info_index[i],1);
		add_edge(human_index[info[i].B],info_index[i],1);
		add_edge(info_index[i],sink,1);
	}

	min_max = 0;
	int flow = 0;

	for(int i = 1; i*N <= M; i++){

		for(int k = 0; k < G[source].size(); k++){
			G[source][k].capacity++;
		}

		flow += max_flow(source,sink);

		if(flow == N*i){
			min_max = i;
		}
	}

	delete_graph();

	for(int i = 0; i < N; i++){
		add_edge(source,human_index[i],0);
	}

	for(int i = 0; i < M; i++){
		add_edge(human_index[info[i].A],info_index[i],1);
		add_edge(human_index[info[i].B],info_index[i],1);
		add_edge(info_index[i],sink,1);
	}

	int max_min;
	flow = 0;

	for(int i = 1; i <= M; i++){

		for(int k = 0; k < G[source].size(); k++){
			G[source][k].capacity++;
		}

		flow += max_flow(source,sink);

		if(flow == M){
			max_min = i;
			break;
		}
	}

	printf("%d %d\n",min_max,max_min);
}

int main(){

	while(true){
		scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)break;

		func();
	}

	return 0;
}

