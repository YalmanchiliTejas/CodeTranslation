#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005

struct Info{
	Info(){
		value = 0;
		index = 0;
	}
	Info(int arg_value,int arg_index){
		value = arg_value;
		index = arg_index;
	}
	int value,index;
};

int N,BIT_N;
Info table[8*NUM];
int input[NUM];
int BIT[NUM];
bool used[NUM];

void add(int loc,int value){

	BIT[loc] += value;

	loc += loc & -loc;

	while(loc <= BIT_N){
		BIT[loc] += value;
		loc += loc & -loc;
	}
}

int getSum(int loc){

	int sum = BIT[loc];

	loc -= loc & -loc;

	while(loc > 0){
		sum += BIT[loc];
		loc -= loc & -loc;
	}
	return sum;
}

int calc(int left,int right){
	return getSum(right)-getSum(left-1);
}

void init(int first_N){
	while(N < first_N)N *= 2;
}

void update(int loc,int value){
	loc += N-1;

	table[loc].value = value; //区間の最小値
	table[loc].index = loc-(N-1); //最小値を持つインデックス

	if(N == 1)return;

	int parent = (loc-1)/2;

	while(true){
		if(table[2*parent+1].value <= table[2*parent+2].value){

			table[parent].value = table[2*parent+1].value;
			table[parent].index = table[2*parent+1].index;

		}else{

			table[parent].value = table[2*parent+2].value;
			table[parent].index = table[2*parent+2].index;
		}

		if(parent == 0)break;
		else{
			parent = (parent-1)/2;
		}
	}
}


Info query(int search_left,int search_right,int node_id,int node_left,int node_right){

	//今回のノードが検索区間をカバーしていなければ、結果に関係ない値を返す
	if(search_right < node_left || search_left > node_right)return Info(NUM,-1);

	//今回のノードの区間が、検索区間の部分区間である場合、今回のノードの値を返す
	if(search_left <= node_left && search_right >= node_right){
		return table[node_id];
	}

	//今回のノードの区間に、一部検索区間と重なっている区間がある場合→再帰的に子どもに尋ねる
	Info left_info = query(search_left,search_right,2*node_id+1,node_left,(node_left+node_right)/2);
	Info right_info = query(search_left,search_right,2*node_id+2,(node_left+node_right)/2+1,node_right);

	if(left_info.value <= right_info.value){

		return left_info;
	}else{

		return right_info;
	}
}


int main(){

	int first_N;
	ll K;

	scanf("%d %lld",&first_N,&K);

	N = 1;
	BIT_N = first_N;
	init(first_N);

	for(int i = 0; i <= BIT_N; i++)BIT[i] = 0;
	//0～N-2が上位構造のアドレス、N-1～2*N-2が最小要素のアドレス
	for(int i = 0; i <= 2*N-2; i++)table[i].value = BIG_NUM;

	ll rev_num = 0;

	for(int loop = 0; loop < first_N; loop++){
		scanf("%d",&input[loop]);
		rev_num += loop-getSum(input[loop]);
		add(input[loop],1);
		update(loop,input[loop]);
	}

	if(rev_num <= K){

		for(int i = 0; i < first_N; i++){

			printf("%d\n",input[i]);
		}
		return 0;
	}

	for(int i = 0; i <= BIT_N; i++)BIT[i] = 0; //BIT木は1オリジン
	for(int i = 1; i <= first_N; i++){
		add(i,1);
		used[i] = false;
	}

	int L,R,mid,range_right;

	rev_num -= K;
	Info info;
	vector<int> ans;

	while(rev_num > 0){

		//2分探索で、要素数がrev_num+1個となる右端を求める
		L = 1,R = first_N,mid = (L+R)/2;
		range_right = first_N;

		while(L <= R){

			if(getSum(mid) >= rev_num+1){

				range_right = mid;
				R = mid-1;
			}else{

				L = mid+1;
			}
			mid = (L+R)/2;
		}

		info = query(0,range_right-1,0,0,N-1); //区間の最小値
		ans.push_back(info.value);
		used[info.value] = true;
		add(info.index+1,-1);
		rev_num -= getSum(info.index);
		update(info.index,BIG_NUM);
	}

	for(int i = 0; i < ans.size(); i++){

		printf("%d\n",ans[i]);
	}

	for(int i = 0; i < first_N; i++){
		if(used[input[i]])continue;
		printf("%d\n",input[i]);
	}

	return 0;
}

