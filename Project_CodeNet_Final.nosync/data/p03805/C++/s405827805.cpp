#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
const int MOD = 1e9+7;
using namespace std;

vector<vector<bool> > graph(9, vector<bool>(9));

int check(vector<int> v){
	for (int i = 0; i < v.size()-1; i++){
		if (graph[v[i]][v[i+1]] == false){
			return 0;
		}
	}
	return 1;
}

int main(){
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	vector<int> v;
	for (int i = 1; i <= n; i++){
		v.push_back(i);
	}

	do{
		ans += check(v); 
	}while(next_permutation(v.begin()+1, v.end()));
	cout << ans << endl;
	return 0;
}