//============================================================================
// Name        : abc54C.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;

map<int, int> mp;
int N, M;

void dfs(vector<vector<int>> &A, int node, int &count){

	if(mp[node] == 1)return;
	mp[node] = 1;

	bool b = true;
	for(int i = 0; i < N; ++i){
		if(mp[i] == 0){b = false;break;}
	}

	if(b)++count;

	for(int i = 0; i < A[node].size(); ++i){
			dfs(A, A[node][i], count);
	}

	mp[node] = 0;
}

int main() {
	cin >> N >> M;

	vector<vector<int>> A(N + 1, vector<int>(0));

	for(int i = 0; i < M; ++i){
		int a, b;
		cin >> a >> b;
		A[a - 1].push_back(b - 1);
		A[b - 1].push_back(a - 1);
	}

	int count = 0;
	mp[0] = 1;
	for(int i = 0; i < A[0].size(); ++i){
		dfs(A, A[0][i], count);
	}

	cout << count << endl;


	return 0;
}
