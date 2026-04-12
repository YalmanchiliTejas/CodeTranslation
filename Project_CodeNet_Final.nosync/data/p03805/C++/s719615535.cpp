#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool graph[10][10];

int main() {
	int n, m;
	cin >> n >> m;
	int a, b;
	int sum,ans=0;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	vector<int>v;
	for (int i = 2; i <= n; ++i)v.push_back(i);
	do{
		sum = 0;
		if (graph[v[0]][1] == false)continue;
		for (int i = 0; i < n - 2; ++i) {
			if (graph[v[i]][v[i + 1]] == true)++sum;
		}
		if (sum == n - 2)++ans;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}