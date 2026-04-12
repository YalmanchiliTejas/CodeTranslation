#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool edge[n][n];
	memset(&edge,0,sizeof(edge));
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edge[a][b] = edge[b][a] = true;
	}
	vector<int> path;
	for(int i = 0; i < n; i ++)
	{
		path.push_back(i);
		//cout << path[i] << " ";
	}
	//cout << endl;
	int total = 0;
	do
	{
		if(path[0] == 0)
		{
			int edges = 0;
			for(int i = 0; i < n-1; i ++)
			{
				if(edge[path[i]][path[i+1]])
				{
					edges++;
				}
			}
			if(edges == n-1)
			{
				total++;
			}
		}
		else
		{
			continue;
		}
	}
	while(next_permutation(path.begin(),path.end()));
	cout << total << endl;
	return 0;
}