//g++ test.cpp -o test.out
//入出力：http://kaitei.net/cpp/iostream/
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
using namespace std;

int N;//頂点の数
int M;//辺の数
int a[28];
int b[28];
int ans = 0;

int num_of_egde[9] = {0,0,0,0,0,0,0,0,0};//i番目の頂点からいくつ辺が伸びているかをnum_of_egde[i]とする
int edge[9][28];//頂点iからいける点をedge[i]に一つずつ格納していく

void order_edge(){
	for(int i=0;i<M;i++){
		edge[a[i]][num_of_egde[a[i]]] = b[i];
		num_of_egde[a[i]]++;
		edge[b[i]][num_of_egde[b[i]]] = a[i];
		num_of_egde[b[i]]++;
	}
}

//present_nodeは現在どの頂点にいるかを表す
//頂点iを訪れたことがあるならばvisited_bitのiビット目は1
void search(int present_node,int visited_bit){
	if((visited_bit >> (present_node-1))&1){//現在の頂点にすでにきたことがあるならば
		return;//条件を満たさないので関数停止
	}
	visited_bit = visited_bit + (1 << (present_node-1));//きたことを記録
	if(visited_bit == ((1<<N)-1)){//すべての頂点を回ったならば
		ans++;
		return;
	}
	for(int i=0;i<num_of_egde[present_node];i++){
		search(edge[present_node][i],visited_bit);
	}
}

void solve(){
	order_edge();
	search(1,0);
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++) cin >> a[i] >> b[i];

	solve();

	cout << ans;
	return 0;
}