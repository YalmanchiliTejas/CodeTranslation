#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int root[4000];
int getRoot(int v){ return root[v] == -1 ? v : root[v] = getRoot(root[v]); }

vector<vector<long long>> solve(int N, const vector<pair<int, pair<int,int>>>& edge){
	fill(root, root+N, -1);
	vector<vector<pair<int,int>>> g(N);
	long long sum = 0;
	for(auto& e : edge){
		int src = e.second.first;
		int dst = e.second.second;
		int p = getRoot(src);
		int q = getRoot(dst);
		if(p != q){
			sum += e.first;
			root[q] = p;
			g[src].emplace_back(dst, e.first);
			g[dst].emplace_back(src, e.first);
		}
	}
	vector<vector<long long>> res(N, vector<long long>(N, -1));
	for(int i=0;i<N;i++){
		res[i][i] = 0;
		queue<int> qu; qu.push(i);
		while(!qu.empty()){
			int pos = qu.front(); qu.pop();
			for(auto& e : g[pos]){
				int dst = e.first;
				if(res[i][dst] >= 0) continue;
				res[i][dst] = max<long long>(res[i][pos], e.second);
				qu.push(dst);
			}
		}
	}
	for(auto& v : res){
		for(auto& t : v) t = sum - t;
	}
	return res;
}

int main(){
	int N, M;
	while(cin >> N >> M){
		vector<pair<int, pair<int, int>>> edge(M);
		for(auto& p : edge){
			cin >> p.second.first >> p.second.second >> p.first;
			--p.second.first;
			--p.second.second;
		}
		sort(edge.begin(), edge.end());
		auto res = solve(N, edge);
		int Q; cin >> Q;
		for(int i=0;i<Q;i++){
			int s, t; cin >> s >> t;
			cout << res[s-1][t-1] << endl;
		}
	}
}
