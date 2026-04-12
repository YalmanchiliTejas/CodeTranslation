#include <bits/stdc++.h>
using namespace std;

int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	int N, M;
	scanf("%d %d", &N, &M);

	vector<vector<bool>> edge(N + 1, vector<bool>(N + 1, false)); //0は使わない
	int a;
	int b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		edge[a][b] = true;
		edge[b][a] = true;
	}
	long long num = 1;
	vector<int> path;
	for (int i = 1; i <= N; i++)
	{
		num = num * i;
		path.insert(path.end(), i);
	}
	bool flag;
	long long result = 0;
	for (int i = 0; i < num; i++)
	{
		if (path[0] != 1)
		{
			next_permutation(path.begin(), path.end());
			continue;
		}
		flag = true;
		// cout << path[0] << " ";
		for (int j = 1; j < N; j++)
		{
			// cout << path[j] << " ";
			if (!edge[path[j - 1]][path[j]])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			result++;
		}
		// cout << ":" << flag << "\n";
		next_permutation(path.begin(), path.end());
	}

	cout << result;
	return 0;
}