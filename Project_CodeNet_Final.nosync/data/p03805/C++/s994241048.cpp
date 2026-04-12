#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> check;
int visitcount;
int result;

void visit(int i)
{
	if (check[i]) return;
	check[i] = true;
	visitcount++;
	if (visitcount == n) result++;
	else for (auto&& ii : graph[i]) visit(ii);
	visitcount--;
	check[i] = false;
}

int main()
{
	cin >> n >> m;
	graph = vector<vector<int>>(n);
	check = vector<bool>(n, false);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	visit(0);
	cout << result << endl;
	return 0;
}
