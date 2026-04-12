// AtCode.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdint.h>
#include <queue>

using namespace std;

typedef vector<vector<int>> Graph;
Graph graph;

bool check(vector<int>& candidate) {
	for (unsigned int i = 0; i < candidate.size()-1; i++) {
		// i番目の数字がi+1番目の数字へのリンクを有しているか否か
		if(!binary_search(graph[candidate[i]].begin(), graph[candidate[i]].end(), candidate[i + 1])) return false;
	}
	return true;
}


int main() {

	int N, M;
	cin >> N >> M;

	graph.resize(N);

	for (int i = 0; i < M; i++) {
		int tmpa, tmpb;
		cin >> tmpa >> tmpb;
		graph[tmpa-1].push_back(tmpb-1);
		graph[tmpb-1].push_back(tmpa-1);
	}

	//0~N-1まで数字を並べた配列を作る
	vector<int> candidate;
	for (int i = 0; i < N; i++) {
		candidate.push_back(i);
		sort(graph[i].begin(), graph[i].end());
	}

	int count = 0;
	do {
		if( check(candidate) ) count++; // 指定の順番で最後まで到達できるかチェック
	} while (next_permutation(candidate.begin()+1,candidate.end())); // start is fixed

	cout << count << endl;
	return 0;

}
