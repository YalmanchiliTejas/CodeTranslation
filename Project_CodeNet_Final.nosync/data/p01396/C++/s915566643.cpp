
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 1005
#define NUM 2010

int H,W;
int table[2][SIZE][SIZE];
int in_num[SIZE];

int V;
vector<int> G[NUM];
int match[NUM];
bool used[NUM];

void add_edge(int from,int to){
	G[from].push_back(to);
	G[to].push_back(from);
}

int dfs(int node_id){
	used[node_id] = true;

	for(int i = 0; i < G[node_id].size(); i++){
		int adj_node_id = G[node_id][i],pair_id = match[adj_node_id];
		if((pair_id < 0)||
				(used[pair_id] == false && dfs(pair_id) == true)){

			match[node_id] = adj_node_id;
			match[adj_node_id] = node_id;
			return true;
		}
	}
	return false;
}


int bipartie_matching(){
	int ret = 0;
	for(int i = 0; i < V; i++)match[i] = -1;
	for(int node_id = 0; node_id < V; node_id++){
		if(match[node_id] < 0){
			for(int i = 0; i < V; i++)used[i] = false;
			if(dfs(node_id)){
				ret++;
			}
		}
	}
	return ret;
}


int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){

			scanf("%d",&table[0][row][col]);
			table[1][col][row] = table[0][row][col];
		}
	}

	bool FLG;

	for(int i = 0; i < 2; i++){

		if(H == 1){
			swap(H,W);
			continue;
		}

		V = 2*H;

		for(int i = 0; i < H; i++){

			in_num[i] = 0;
		}

		for(int a = 0; a < H; a++){
			for(int b = 0; b < H; b++){
				if(b == a)continue;

				FLG = true;
				for(int k = 0; k < W; k++){
					if(table[i][a][k] < table[i][b][k]){

						FLG = false;
						break;
					}
				}
				if(!FLG)continue;

				add_edge(a,b+H);
				in_num[b]++;
			}
		}

		int count = 0;
		for(int i = 0; i < H; i++){

			if(in_num[i] > 0)count++;
		}
		if(count != H-1){

			printf("NO\n");
			return 0;
		}

		int num_match = bipartie_matching();

		//printf("i:%d num_match:%d\n",i,num_match);

		if(H-num_match > 2){

			printf("NO\n");
			return 0;
		}

		for(int a = 0; a < V; a++){

			G[a].clear();
		}

		swap(H,W);
	}

	printf("YES\n");

	return 0;
}

