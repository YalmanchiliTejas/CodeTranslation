#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	int ans = 0;
	cin >> N >> M;

	vector<vector<int>> nodes(N);

	for (int i = 0;i < M;i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	vector<int> p(N);
	for (int i = 0;i < N;i++)
		p[i] = i;

	do
	{
		//スタートは頂点1番から
		if (p[0] != 0)
			continue;

		//すべての頂点に道があるか
		bool all_found = true;
		for (int i = 1;i < N;i++)
		{
			//次の頂点への道があるか
			bool found = false;
			for (int j = 0;j < nodes[p[i - 1]].size();j++)
			{
				if (nodes[p[i - 1]][j] == p[i])
				{
					found = true;
					break;
				}
			}

			//行くことができない場合
			if (!found)
			{
				all_found = false;
				break;
			}
		}

		//すべて通ることができる場合
		if (all_found)
			ans++;

	} while (next_permutation(p.begin(), p.end()));

	cout << ans << endl;

	return 0;
}
