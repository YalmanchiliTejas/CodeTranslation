#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>>& edge, vector<bool>& done, int p = 0){
	int r = 0;
	done[p] = true;
	bool f = true;
	for(int i = 0; i < done.size(); i++) f &= done[i];
	if(f){
		done[p] = false;
		return 1;
	}
	for(int i = 0; i < edge[p].size(); i++){
		if(done[edge[p][i]]) continue;
		r += solve(edge, done, edge[p][i]);
	}
	done[p] = false;
	return r;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<bool> done(n, false);
	vector<vector<int>> edge(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	cout << solve(edge, done) << endl;
}