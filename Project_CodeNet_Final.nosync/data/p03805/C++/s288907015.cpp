#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


const int nmax=8;
 bool graph[nmax][nmax];

 int dfs(int v,int N,bool visited[nmax]){

	bool all_visited=true;

	//すべて訪問したかチェック
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}

	//すべて訪問可能なルートを数える為
	if (all_visited) {

		return 1;
	}

	int ret = 0; //ルートの数

	//グラフ上でつながって
	//まだ訪れたことがない
	for (int j = 0; j < N; j++) {

		//v==0からスタート
		if (graph[v][j]==false) {
			continue;
		}

		if (visited[j]) {
			continue;
		}

		visited[j] = true;
		ret += dfs(j, N, visited);
		visited[j] = false;

	}

	return ret;
 }

 int main(void){
	 int N,M;
	 cin >> N >> M;

	 //二次元のグラフを作成
	 for(int i=0;i<M;++i){
	 int A,B;
	 cin >> A >> B;
	 graph[A-1][B-1]=graph[B-1][A-1]=true;
	}
	 
	 //訪問先配列初期化
	 bool visited[nmax];
	 for(int i=0;i<N;++i){
	 visited[i]=false;
	 }

	 visited[0]=true;
	 cout << dfs(0,N,visited) << endl;
	 return 0;
 }
