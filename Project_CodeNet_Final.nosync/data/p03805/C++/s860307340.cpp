#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> edges(N, vector<bool>(N, false));
	rep(i, M)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		edges[a][b] = true;
		edges[b][a] = true;
	}

	vector<int> indices;
	for (int i = 1; i < N; ++i)
	{
		indices.push_back(i);
	}

	int ans = 0;
	do {
		int index = 0;
		bool isSatisfied = true;
		rep(i, indices.size())
		{
			if (!edges[index][indices[i]])
			{
				isSatisfied = false;
				break;
			}

			index = indices[i];
		}

		if (isSatisfied) ++ans;
	} while (next_permutation(indices.begin(), indices.end()));

	cout << ans << endl;
}