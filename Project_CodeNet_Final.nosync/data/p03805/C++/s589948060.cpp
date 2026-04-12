#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
using Graph = vector<vector<int>>;

vector<int> path; //パス

int N, M;

void dfs(const Graph &G, int v, long long &ans){
	if(path.size() == N){
		ans++;
		return;
	}

	for(auto nv : G[v]){
		int found = 0;
		for(int i=0; i<path.size(); i++){
			if(path[i] == nv){
				found = 1;
				break;
			}
		}
		if(found == 1) continue;
		path.push_back(nv);
		dfs(G, nv, ans);
		path.pop_back();
	}
}

int main(int argc, char* argv[]){
	cin >> N >> M;
  
	Graph G(N+1);
	for(int i=1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b); G[b].push_back(a);
	}

	long long ans = 0;
	path.push_back(1);
	dfs(G, 1, ans);
	cout << ans << endl ;
	return 0;
}