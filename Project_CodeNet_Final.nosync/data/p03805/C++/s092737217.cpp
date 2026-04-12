#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <functional>
using namespace std;
using ll = long long;
int dfs(int N, int p, vector<bool> v, vector<vector<bool>> ab);

int main() {
	int N, M, p;
	cin >> N >> M;
	vector<vector<bool>> ab(N, vector<bool>(N));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ab[a-1][b-1] = ab[b-1][a-1] = true;
	}
	vector<bool> v(N,false);
	v[0] = true;
	cout << dfs(N, 0, v, ab) << endl;
	return 0;
}

int dfs(int N, int p, vector<bool> v, vector<vector<bool>> ab){
	bool all_v = true;
	for (int i = 0; i < N; i++) {
		if(!v[i]) all_v = false;
	}
	if (all_v) return 1;

	int root = 0;
	for (int i = 0; i < N; i++) {
		if (!ab[p][i]) continue;
		if (v[i]) continue;
		v[i] = true;
		root += dfs(N, i, v, ab);
		v[i] = false;
	}
	return root;
}