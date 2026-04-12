#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

int N, num,u,v,L,R;
long long ans,w, A[MAX_N], Answer[MAX_N], pref[MAX_N][2];
bool used[MAX_N];
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
		pref[i][0] = pref[i - 1][0];
		pref[i][1] = pref[i - 1][1];
		pref[i][i & 1] += A[i];
	}

	while (num < N / 2)
	{
		w = pq.top().first;
		u = pq.top().second.first;
		v = pq.top().second.second;
		pq.pop();
		if (used[u] || used[v])
		{
			continue;
		}
		used[u] = true, used[v] = true;
		unused.erase(u);
		unused.erase(v);
		num++;
		ans += w;
		L = *prev(unused.lower_bound(u));
		R = *unused.lower_bound(v);

		if (1 <= L && R <= N + 1) 
		{
			pq.push({ (pref[R - 1][L & 1] - pref[L - 1][L & 1]) - (pref[R - 1][(L & 1) ^ 1] - pref[L - 1][(L & 1) ^ 1]), {L, R} });
		}
	}
	cout << ans << endl;
	return 0;
}
