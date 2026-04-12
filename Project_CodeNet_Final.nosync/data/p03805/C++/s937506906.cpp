#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <vector>
#include <math.h>
#include <string>
#include <queue>

using namespace std;



int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> edge(N+1, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].emplace_back(b);
		edge[b].emplace_back(a);
	}

	vector<int> s;
	for (int i = 1; i <= N; i++)
	{
		s.push_back(i);
	}

	int count = 0;
	do
	{
		bool flag = true;

		for (int i = 0; i < s.size() - 1; i++)
		{
			bool tmp = false;

			for (int j = 0; j < edge[s[i]].size(); j++)
			{
				if (edge[s[i]][j] == s[i + 1])
				{
					tmp = true;
					break;
				}
			}

			if (!tmp)
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			count++;
		}

	} while (next_permutation(s.begin() + 1, s.end()));


	cout << count << endl;

	return 0;
}