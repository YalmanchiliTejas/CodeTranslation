#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


struct Edge{
	Edge(int arg_to,int arg_cost){
		to = arg_to;
		cost = arg_cost;
	}
	int to,cost;
};

struct Info{
	Info(int arg_node_id,int arg_depth){
		node_id = arg_node_id;
		depth = arg_depth;
	}
	bool operator<(const struct Info &arg) const{
		return depth < arg.depth;
	}

	int node_id,depth;
};


int *depth_table,*parent,*num_table,*all_alive_table,*one_delete_table;
vector<Edge> G[100000];

void calcDepth(int node_id,int depth,int parent_id){
	depth_table[node_id] = depth;
	parent[node_id] = parent_id;
	for(int i = 0; i < G[node_id].size(); i++){
		if(G[node_id][i].to == parent_id)continue;
		calcDepth(G[node_id][i].to,depth+1,node_id);
	}
}

int main(){

	int N,K;
	scanf("%d %d",&N,&K);

	depth_table = new int[N];
	parent = new int[N];
	num_table = new int[N];
	all_alive_table = new int[N];
	one_delete_table = new int[N];

	int from,to;
	for(int loop = 0; loop < N-1; loop++){
		scanf("%d %d",&from,&to);
		from--;
		to--;
		G[from].push_back(Edge(to,1));
		G[to].push_back(Edge(from,1));
	}

	calcDepth(0,0,-1);
	priority_queue<Info> Q;

	for(int i = 0; i < N; i++){
		Q.push(Info(i,depth_table[i]));
	}


	int tmp_num;
	int maximum = 0,all_alive_num,one_delete_num,one_delete_max,two_delete_num,two_delete_max;

	while(!Q.empty()){

		tmp_num = 1;
		all_alive_num = 0;

		for(int i = 0; i < G[Q.top().node_id].size(); i++){
			if(G[Q.top().node_id][i].to == parent[Q.top().node_id])continue;
			tmp_num += num_table[G[Q.top().node_id][i].to];
			if(num_table[G[Q.top().node_id][i].to] >= K){
				all_alive_num++;
			}
		}

		one_delete_max = 0;
		two_delete_max = 0;
		for(int i = 0; i < G[Q.top().node_id].size(); i++){
			if(G[Q.top().node_id][i].to == parent[Q.top().node_id])continue;

			if(num_table[G[Q.top().node_id][i].to] >= K){
				two_delete_num =(one_delete_max-1)+max(all_alive_table[G[Q.top().node_id][i].to],one_delete_table[G[Q.top().node_id][i].to]);
			}else{
				two_delete_num =(one_delete_max)+max(all_alive_table[G[Q.top().node_id][i].to],one_delete_table[G[Q.top().node_id][i].to]);
			}
			two_delete_max = max(two_delete_max,two_delete_num);

			if(num_table[G[Q.top().node_id][i].to] >= K){
				one_delete_num =(all_alive_num-1)+max(all_alive_table[G[Q.top().node_id][i].to],one_delete_table[G[Q.top().node_id][i].to]);
			}else{
				one_delete_num =(all_alive_num)+max(all_alive_table[G[Q.top().node_id][i].to],one_delete_table[G[Q.top().node_id][i].to]);
			}
			one_delete_max = max(one_delete_max,one_delete_num);

		}

		num_table[Q.top().node_id] = tmp_num;
		all_alive_table[Q.top().node_id] = all_alive_num;
		one_delete_table[Q.top().node_id] = one_delete_max;

		if(G[Q.top().node_id].size() > 1 && N-num_table[Q.top().node_id] >= K){
			one_delete_max++;
			two_delete_max++;
		}
		maximum = max(maximum,max(one_delete_max,two_delete_max));
		Q.pop();
	}

	printf("%d\n",maximum);

	return 0;
}