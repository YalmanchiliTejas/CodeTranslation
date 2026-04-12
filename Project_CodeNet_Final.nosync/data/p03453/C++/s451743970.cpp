#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, m, i, j, k, s, t, a, b, d, ans, id, MOD = 1000000007, ex;
	cin >> n >> m >> s >> t;
	vector<vector<pair<long long, long long>>> edge(n + 1);
	for (i = 0; i < m; i++) {
		cin >> a >> b >> d;
		edge[a].push_back({ d, b });
		edge[b].push_back({ d, a });
	}
	for (i = 1; i <= n; i++) sort(edge[i].begin(), edge[i].end());

	vector<long long> dist1, dist2, dp1, dp2;
	priority_queue<pair<long long, long long>> q;	

	// move from S
	dist1.assign(n + 1, 1LL << 60);
	dp1.assign(n + 1, 0);
	dist1[s] = 0;
	q.push({ 0, s });

	while (!q.empty()) {
		id = q.top().second;
		d = -q.top().first; 
		q.pop();
		if (dist1[id] != d) continue;

		if (id == s) dp1[s] = 1;
		else {
			for (auto p : edge[id]) {
				if (dist1[p.second] + p.first == d) dp1[id] = (dp1[id] + dp1[p.second]) % MOD;
			}
		}

		for (auto p : edge[id]) {
			if (d + p.first < dist1[p.second]) {
				dist1[p.second] = d + p.first;
				q.push({ -dist1[p.second], p.second });
			}
		}
	}

	// move from t
	dist2.assign(n + 1, 1LL << 60);
	dp2.assign(n + 1, 0);
	dist2[t] = 0;
	q.push({ 0, t });

	while (!q.empty()) {
		id = q.top().second;
		d = -q.top().first;
		q.pop();
		if (dist2[id] != d) continue;

		if (id == t) dp2[t] = 1;
		else {
			for (auto p : edge[id]) {
				if (dist2[p.second] + p.first == d) dp2[id] = (dp2[id] + dp2[p.second]) % MOD;
			}
		}

		for (auto p : edge[id]) {
			if (d + p.first < dist2[p.second]) {
				dist2[p.second] = d + p.first;
				q.push({ -dist2[p.second], p.second });
			}
		}
	}
	
	ans = (dp1[t] * dp1[t]) % MOD;
	ex = 0;
	d = dist1[t];
	if (d % 2 == 0) {
		// meet at the same vertice
		for (i = 1; i <= n; i++) {
			if ((dist1[i] == d / 2) && (dist2[i] == d / 2)) {
				ex = (ex + ((dp1[i] * dp1[i]) % MOD) * ((dp2[i] * dp2[i]) % MOD)) % MOD;
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (auto p : edge[i]) {
			a = i; b = p.second; 
			if ((dist1[a] * 2 < d) && (dist2[b] * 2 < d) && (dist1[a] + dist2[b] + p.first == d)) {
				// meet on the edge
				ex = (ex + ((dp1[a] * dp1[a]) % MOD) * ((dp2[b] * dp2[b]) % MOD)) % MOD;
			}
		}
	}

	ans = (ans + MOD + MOD - ex) % MOD;
	cout << ans << "\n";

	return 0;
}
