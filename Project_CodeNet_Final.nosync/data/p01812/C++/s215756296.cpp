#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
long long int INF = 1e18;

vector<int> E[(1 << 17)];

bool used[(1 << 17)] = {};

int main(){
	
	int N, M, K;
	cin >> N >> M >> K;
	
	bool D[200] = {};
	map<int, int> m;
	
	for(int i = 0; i < M; i++){
		int num;
		cin >> num;
		D[num] = true;
		m[num] = i;
	}
	
	int v[200][200];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < K; j++){
			cin >> v[i][j];
		}
	}
	
	for(int i = 0; i < K; i++){
		int to[100] = {};
		for(int j = 1; j <= N; j++){
			if(D[j] && !D[v[j - 1][i]]){
				to[m[j]] = -1;
			}else if(D[j]){
				to[m[j]] = m[v[j - 1][i]];
			}
		}
		/*
		for(int j = 0; j < M; j++){
			cout << to[j] << endl;
		}
		*/
		for(int j = 0; j < (1 << M); j++){
			int t = 0;
			for(int k = 0; k < M; k++){
				if(j & (1 << k) && to[k] != -1){
					t |= (1 << to[k]);
				}
			}
			E[j].push_back(t);
			//cout << j << " " << t << endl;
		}
	}
	
	queue<int> que;
	int ans;
	
	que.push((1 << M) - 1);
	for(int loop = 0; !que.empty(); loop++){
		int sz = que.size();
		for(int i = 0; i < sz; i++){
			int hoge = que.front();
			que.pop();
			if(used[hoge]){
				continue;
			}
			used[hoge] = true;
			if(hoge == 0){
				ans = loop;
			}
			for(int k = 0; k < E[hoge].size(); k++){
				que.push(E[hoge][k]);
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
