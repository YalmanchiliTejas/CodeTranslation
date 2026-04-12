#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 600001


int N = 1;
int euler_index,root;
int num_count[NUM][10],change_table[NUM][10];
bool changed[NUM];
int LEFT[100000],RIGHT[100000];
vector<int> G[100000];


void init(int first_N){
	while(N < first_N)N *= 2;
}

//最初、全ての電球の明るさは0
void add(int loc){
	loc += N-1;

	num_count[loc][0] += 1;

	while(loc > 0){
		loc = (loc-1)/2;
		num_count[loc][0] = num_count[2*loc+1][0]+num_count[2*loc+2][0];
	}
}

void update_array(int node_id,int next_array[10]){

	//★★まとめて変更する場合は、まとめて処理する★★
	int next_count[10];
	for(int i = 0; i <= 9; i++)next_count[i] = 0;

	for(int i = 0; i <= 9; i++){
		next_count[next_array[i]] += num_count[node_id][i];
	}
	int next_change_table[10];
	for(int i = 0; i <= 9; i++){
		next_change_table[i] = next_array[change_table[node_id][i]];
	}

	for(int i = 0; i <= 9; i++){
		num_count[node_id][i] = next_count[i];
		change_table[node_id][i] = next_change_table[i];
	}

	changed[node_id] = true;
}


void update(int update_left,int update_right,int node_id,int node_left,int node_right,int x,int y){

	if(update_right < node_left || update_left > node_right)return; //範囲外なら何もしない
	else if(update_left <= node_left && update_right >= node_right){ //このノードのカバー区間が、更新区間の部分区間である場合

		for(int i = 0; i <= 9; i++){
			if((change_table[node_id][i] == x)){
				change_table[node_id][i] = y; //変換対応を更新
			}
		}
		num_count[node_id][y] += num_count[node_id][x]; //★★iをyに足すのは間違い!xを足す★★
		num_count[node_id][x] = 0;

		changed[node_id] = true;

		return; //更新は子方向に伝えない

	}else{
		//このノードのカバー範囲と更新範囲に部分的な重なりがある場合
		//現在自分が★蓄積していた(子供に伝えていなかった)★変換情報を子に投げる(★★更新区間が、node_left～node_rightであることに注意★★)

		if(changed[node_id]){
			update_array(2*node_id+1,change_table[node_id]);
			update_array(2*node_id+2,change_table[node_id]);

			//情報を伝えたので変換表をリセット
			for(int i = 0; i <= 9; i++){
				change_table[node_id][i] = i;
			}
			changed[node_id] = false;
		}

		//改めて今回のクエリを投げる
		update(update_left,update_right,2*node_id+1,node_left,(node_left+node_right)/2,x,y);
		update(update_left,update_right,2*node_id+2,(node_left+node_right)/2+1,node_right,x,y);

		//★★子にクエリを投げた結果、このノードの以下の集計が変わるので、ボトムアップ的に再帰的に計算する
		for(int i = 0; i <= 9; i++){
			num_count[node_id][i] = num_count[2*node_id+1][i]+num_count[2*node_id+2][i];
		}
	}
}




int getSum(int search_left,int search_right,int node_id,int node_left,int node_right,int x,int y){
	if(search_right < node_left || search_left > node_right){
		return 0;
	}else if(search_left <= node_left && search_right >= node_right){

		int ret = 0;
		for(int i = x; i <= y; i++){
			ret += num_count[node_id][i];
		}

		return ret;

	}else{

		//★★貯めていた情報を下に伝える★★
		update_array(2*node_id+1,change_table[node_id]);
		update_array(2*node_id+2,change_table[node_id]);

		//情報を伝えたので変換表をリセット
		for(int i = 0; i <= 9; i++){
			change_table[node_id][i] = i;
		}

		//★★自分より下の、数の個数情報は、updateの際に把握しているので変更不要★★

		int left = getSum(search_left,search_right,2*node_id+1,node_left,(node_left+node_right)/2,x,y);
		int right = getSum(search_left,search_right,2*node_id+2,(node_left+node_right)/2+1,node_right,x,y);
		return left+right;
	}
}


//オイラーツアーで、ノードのカバー範囲を計算する
void euler_tour(int node_id,int pre_node){
	LEFT[node_id] = euler_index++;

	for(int i = 0; i < G[node_id].size(); i++){
		if(G[node_id][i] == pre_node)continue;
		euler_tour(G[node_id][i],node_id);
	}
	RIGHT[node_id] = euler_index++;
}

int main(){

	euler_index = 0;
	root = 0;

	int V,Q;
	scanf("%d %d",&V,&Q);

	int from,to;

	for(int loop = 0; loop < V-1; loop++){
		scanf("%d %d",&from,&to);
		G[from].push_back(to);
		G[to].push_back(from);
	}

	euler_tour(root,-1);

	int first_N = RIGHT[root]+1; //セグ木における最下層のノードは、最低RIGHT[root]+1個あれば良い(+1は0オリジンのため)

	init(first_N);

	//変換配列および集計配列の初期化
	for(int i = 0; i <= 2*N-2; i++){
		for(int k = 0; k <= 9; k++){
			num_count[i][k] = 0;
			change_table[i][k] = k;
		}
		changed[i] = false;
	}

	//有効ノードの個数を、セグメント木に反映させる
	for(int i = 0; i < V; i++){
		add(LEFT[i]);
	}

	int command,node_id,x,y;

	for(int loop = 0; loop < Q; loop++){

		scanf("%d %d %d %d",&command,&node_id,&x,&y);

		if(command == 1){ //計上

			printf("%d\n",getSum(LEFT[node_id],RIGHT[node_id],0,0,N-1,x,y));

		}else{ //更新

			if(x == y)continue;

			update(LEFT[node_id],RIGHT[node_id],0,0,N-1,x,y);
		}
	}

	return 0;
}


