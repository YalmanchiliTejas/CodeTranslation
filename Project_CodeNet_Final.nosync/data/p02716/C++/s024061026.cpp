#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

int N, cnt, u, v, L, R;
long long ans, w, A[MAX_N], SUM[MAX_N][2];
priority_queue<pair<long long, pair<int, int>>> pq;
set<int> unused;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++)
	{
		pq.push({ A[i], {i, i + 1} });
	}

	for (int i = 0; i <= N + 2; i++)
	{
		unused.emplace(i);
	}

	for (int i = 1; i <= N + 2; i++)
	{
		SUM[i][0] = SUM[i - 1][0];
		SUM[i][1] = SUM[i - 1][1];
		SUM[i][i & 1] += A[i];
	}

	while (cnt < N / 2)
	{
		w = pq.top().first;
		u = pq.top().second.first;
		v = pq.top().second.second;
		pq.pop();

		if (unused.find(u) != unused.end() && unused.find(v) != unused.end())
		{
			unused.erase(u);
			unused.erase(v);
			cnt++;
			ans += w;
			L = *prev(unused.lower_bound(u));
			R = *unused.lower_bound(v);
			if (1 <= L && R <= N + 1)
			{
				pq.push({ (SUM[R - 1][L & 1] - SUM[L - 1][L & 1]) - (SUM[R - 1][(L & 1) ^ 1] - SUM[L - 1][(L & 1) ^ 1]), {L, R} });
			}
		}
	}

	cout << ans << endl;
	return 0;
}