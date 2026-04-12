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


enum Type{
	Hero,
	Warrior,
	Cleric,
	Mage,
};

enum Which{
	IN,
	OUT,
};

#define NUM 500


//辺を表す構造体(行先、容量、逆辺のインデックス)
struct Edge{
	Edge(int arg_to,int arg_capacity,int arg_rev_index){
		to = arg_to;
		capacity = arg_capacity;
		rev_index = arg_rev_index;
	}
	int to,capacity,rev_index;
};

int V,E;

vector<Edge> G[NUM]; //グラフの隣接リスト表現
int dist[NUM]; //sourceからの距離
int cheked_index[NUM]; //どこまで調べ終わったか
int H,W,C,M,N_w,N_c,N_m;

//fromからtoへ向かう容量capacityの辺をグラフに追加する
void add_edge(int from,int to,int capacity){
	G[from].push_back(Edge(to,capacity,G[to].size()));
	G[to].push_back(Edge(from,0,G[from].size()-1)); //逆辺の、初期容量は0
}

//sourceからの最短距離をBFSで計算する
void bfs(int source){
	for(int i = 0; i < V; i++)dist[i] = -1;
	queue<int> Q;
	dist[source] = 0;
	Q.push(source);

	while(!Q.empty()){
		int node_id = Q.front();
		Q.pop();
		for(int i = 0; i < G[node_id].size(); i++){
			Edge &e = G[node_id][i];
			if(e.capacity > 0 && dist[e.to] < 0){ //辺の容量が正で、かつエッジの行先に未訪問の場合
				dist[e.to] = dist[node_id]+1;
				Q.push(e.to);
			}
		}
	}
}

//増加パスをDFSで探す
int dfs(int node_id,int sink,int flow){
	if(node_id == sink)return flow; //終点についたらflowをreturn

	for(int &i = cheked_index[node_id]; i < G[node_id].size(); i++){ //node_idから出ているエッジを調査
		Edge &e = G[node_id][i];
		if(e.capacity > 0 && dist[node_id] < dist[e.to]){ //流せる余裕があり、かつsourceからの距離が増加する方法である場合
			int tmp_flow = dfs(e.to,sink,min(flow,e.capacity)); //流せるだけ流す
			if(tmp_flow > 0){ //流せた場合
				e.capacity -= tmp_flow; //流した分、エッジの容量を削減する
				G[e.to][e.rev_index].capacity += tmp_flow; //逆辺の容量を、流した分だけ増加させる
				return tmp_flow;
			}
		}
	}
	return 0;
}


//sourceからsinkへの最大流を求める
int max_flow(int source,int sink){ //source:始点 sink:終点
	int flow = 0,add;
	while(true){ //増加パスが存在する限り、流量を追加し続ける
		bfs(source);
		if(dist[sink] < 0)break; //sourceからsinkへと辿り着く残余グラフがない、つまり増加パスが無くなった場合、break
		for(int i = 0; i < V; i++)cheked_index[i] = 0;
		while((add = dfs(source,sink,BIG_NUM)) > 0){ //増加パスが見つかる間、加算
			flow += add;
		}
	}
	return flow;
}


void func(){

	for(int i = 0; i < NUM; i++)G[i].clear();

	int source = 0,sink = 1,index = 2;

	int index_table[55][4][2],no_warrior_in,no_warrior_out,no_cleric_in,no_cleric_out,no_mage_in;

	//ノードを採番する

	//勇者
	for(int i = 0; i < H; i++){
		index_table[i][Hero][IN] = index++;
		index_table[i][Hero][OUT] = index++;
		add_edge(source,index_table[i][Hero][IN],1); //sourceから1の辺を張る
		add_edge(index_table[i][Hero][IN],index_table[i][Hero][OUT],1);//流出量を1に絞るための辺
	}
	//戦士
	for(int i = 0; i < W; i++){
		index_table[i][Warrior][IN] = index++;
		index_table[i][Warrior][OUT] = index++;
		add_edge(index_table[i][Warrior][IN],index_table[i][Warrior][OUT],1);
	}
	//僧侶
	for(int i = 0; i < C; i++){
		index_table[i][Cleric][IN] = index++;
		index_table[i][Cleric][OUT] = index++;
		add_edge(index_table[i][Cleric][IN],index_table[i][Cleric][OUT],1);
	}
	//魔導士
	for(int i = 0; i < M; i++){
		index_table[i][Mage][IN] = index++;
		index_table[i][Mage][OUT] = index++;
		add_edge(index_table[i][Mage][IN],index_table[i][Mage][OUT],1);
	}
	no_warrior_in = index++;
	no_warrior_out = index++;
	for(int i = 0; i < H; i++){
		add_edge(index_table[i][Hero][OUT],no_warrior_in,1); //各勇者(出)から、戦士なしノード(入)に辺を張る
	}
	add_edge(no_warrior_in,no_warrior_out,N_w);

	no_cleric_in = index++;
	no_cleric_out = index++;
	add_edge(no_cleric_in,no_cleric_out,N_c);

	no_mage_in = index++;
	add_edge(no_mage_in,sink,N_m); //魔導士なしからは、直接sinkに容量N_mの辺を張る

	V = index;

	int num,tmp;
	for(int i = 0; i < W; i++){
		add_edge(index_table[i][Warrior][OUT],no_cleric_in,1); //各戦士(出)から、僧侶なしノード(入)に辺を張る
		scanf("%d",&num);
		for(int k = 0; k < num; k++){
			scanf("%d",&tmp);
			tmp--;
			add_edge(index_table[tmp][Hero][OUT],index_table[i][Warrior][IN],1); //仲の良い戦士と勇者に辺を張る
		}
	}

	for(int i = 0; i < C; i++){
		add_edge(no_warrior_out,index_table[i][Cleric][IN],1); //戦士なしノード(出)から、各僧侶(入)に辺を張る
		add_edge(index_table[i][Cleric][OUT],no_mage_in,1); //各僧侶(出)から、魔導士なしノード(入)に辺を張る
		scanf("%d",&num);
		for(int k = 0; k < num; k++){
			scanf("%d",&tmp);
			tmp--;
			add_edge(index_table[tmp][Warrior][OUT],index_table[i][Cleric][IN],1); //仲の良い僧侶と戦士に辺を張る
		}
	}

	for(int i = 0; i < M; i++){
		add_edge(no_cleric_out,index_table[i][Mage][IN],1); //僧侶なしノード(出)から、各魔導士(入り)に辺を張る
		add_edge(index_table[i][Mage][OUT],sink,1); //各魔導士(出)から、sinkに辺を張る
		scanf("%d",&num);
		for(int k = 0; k < num; k++){
			scanf("%d",&tmp);
			tmp--;
			add_edge(index_table[tmp][Cleric][OUT],index_table[i][Mage][IN],1); //仲の良い魔導士と僧侶に辺を張る
		}
	}

	printf("%d\n",max_flow(source,sink));
}


int main(){

	while(true){
		scanf("%d %d %d %d %d %d %d",&H,&W,&C,&M,&N_w,&N_c,&N_m);
		if(H == -1)break;

		func();
	}

	return 0;
}

