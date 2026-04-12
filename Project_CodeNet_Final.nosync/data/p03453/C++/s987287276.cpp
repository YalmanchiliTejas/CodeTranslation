#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <functional>
#include <map>
#include <cmath>
using namespace std;

long long N, M, S, T, a[200009], b[200009], c[200009], dist[200009], dp1[200009], dp2[200009], mod = 1000000007;
vector<pair<long long, long long>>x[200009]; vector<int> y[200009], z[200009];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>Q;
bool used1[200009];

int main() {
	cin >> N >> M >> S >> T;
	for (int i = 1; i <= M; i++) {
		cin >> a[i] >> b[i] >> c[i];
		x[a[i]].push_back(make_pair(b[i], c[i]));
		x[b[i]].push_back(make_pair(a[i], c[i]));
	}
	for (int i = 1; i <= N; i++) dist[i] = (1LL << 60);
	Q.push(make_pair(0, S)); dist[S] = 0;
	while (!Q.empty()) {
		pair<long long, long long>a1 = Q.top(); Q.pop();
		for (int i = 0; i < x[a1.second].size(); i++) {
			long long to = x[a1.second][i].first, cost = x[a1.second][i].second;
			if (dist[to] > dist[a1.second] + cost) {
				dist[to] = dist[a1.second] + cost;
				Q.push(make_pair(dist[to], to));
			}
		}
	}
	queue<int>R; R.push(T);
	while (!R.empty()) {
		int pos = R.front(); R.pop();
		for (int i = 0; i < x[pos].size(); i++) {
			long long to = x[pos][i].first, cost = x[pos][i].second;
			if (dist[to] == dist[pos] - cost) {
				if (used1[to] == false) { used1[to] = true; R.push(to); }
				y[to].push_back(pos);
				z[pos].push_back(to);
			}
		}
	}
	

	vector<pair<long long, long long>>A;
	for (int i = 1; i <= N; i++) A.push_back(make_pair(dist[i], i));
	sort(A.begin(), A.end());
	dp1[S] = 1;
	for (int i = 0; i < A.size(); i++) {
		int pos = A[i].second;
		for (int j = 0; j < y[pos].size(); j++) {
			dp1[y[pos][j]] += dp1[pos];
			dp1[y[pos][j]] %= mod;
		}
	}
	dp2[T] = 1;
	for (int i = A.size() - 1; i >= 0; i--) {
		int pos = A[i].second;
		for (int j = 0; j < z[pos].size(); j++) {
			dp2[z[pos][j]] += dp2[pos];
			dp2[z[pos][j]] %= mod;
		}
	}
	long long ret = dp1[T] * dp1[T]; ret %= mod;
	for (int i = 1; i <= N; i++) {
		if (dist[i] * 2LL == dist[T]) {
			long long E = dp1[i] * dp2[i]; E %= mod; E *= E; E %= mod;
			ret -= E; ret += mod; ret %= mod;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < y[i].size(); j++) {
			int to = y[i][j];
			if (dist[i] * 2LL < dist[T] && dist[T] < dist[to] * 2LL) {
				long long E = dp1[i] * dp2[to]; E %= mod; E *= E; E %= mod;
				ret -= E; ret += mod; ret %= mod;
			}
		}
	}
	cout << ret << endl;
	return 0;
}