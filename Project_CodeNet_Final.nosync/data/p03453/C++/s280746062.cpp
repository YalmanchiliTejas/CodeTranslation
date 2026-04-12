#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	cin >> L >> R;
	vector<vector<pair<int, long long int>>>edge(N + 1);
	vector<long long int>dis(N + 1, LLONG_MAX/10);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b >> K;
		edge[a].push_back({ b,K });
		edge[b].push_back({ a,K });
	}
	dis[L] = 0;
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>>PQ;
	PQ.push({ 0,L });
	while (!PQ.empty()) {
		auto box = PQ.top();
		PQ.pop();
		int cn = box.second;
		long long int c = box.first;
		if (dis[cn] < c) {
			continue;
		}
		for (auto i : edge[cn]) {
			if (dis[i.first] > c + i.second) {
				dis[i.first] = c + i.second;
				PQ.push({ dis[i.first],i.first });
			}
		}
	}
	vector<long long int>aoki_dis(N + 1, LLONG_MAX/10);
	aoki_dis[R] = 0;
	PQ.push({ 0,R });
	while (!PQ.empty()) {
		auto box = PQ.top();
		PQ.pop();
		int cn = box.second;
		long long int c = box.first;
		if (aoki_dis[cn] < c) {
			continue;
		}
		for (auto i : edge[cn]) {
			if (aoki_dis[i.first] > c + i.second) {
				aoki_dis[i.first] = c + i.second;
				PQ.push({ aoki_dis[i.first],i.first });
			}
		}
	}
	vector<long long int>takahashi(N + 1, 0);
	vector<bool>flag(N + 1, true);
	takahashi[L] = 1;
	PQ.push({ 0,L });
	while (!PQ.empty()) {
		auto box = PQ.top();
		PQ.pop();
		int cn = box.second;
		long long int c = box.first;
		if (!flag[cn]) {
			continue;
		}
		flag[cn] = false;
		for (auto i : edge[cn]) {
			if (aoki_dis[L] - aoki_dis[i.first] == c + i.second) {
				takahashi[i.first] += takahashi[cn];
				takahashi[i.first] %= MOD;
				PQ.push({ aoki_dis[L] - aoki_dis[i.first],i.first });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		flag[i] = true;
	}
	vector<long long int>aoki(N + 1, 0);
	aoki[R] = 1;
	PQ.push({ 0, R });
	while (!PQ.empty()) {
		auto box = PQ.top();
		PQ.pop();
		int cn = box.second;
		long long int c = box.first;
		if (!flag[cn]) {
			continue;
		}
		flag[cn] = false;
		for (auto i : edge[cn]) {
			if (dis[R] - dis[i.first] == c + i.second) {
				aoki[i.first] += aoki[cn];
				aoki[i.first] %= MOD;
				PQ.push({ dis[R] - dis[i.first],i.first });
			}
		}
	}
	long long int ans = takahashi[R] * aoki[L];
	ans %= MOD;
	for (int i = 1; i <= N; i++) {
		for (auto j : edge[i]) {
			if (dis[i] + aoki_dis[i] == dis[R] && dis[j.first] + aoki_dis[j.first] == dis[R] && dis[j.first] + j.second == dis[i]) {
				if (dis[i] <= dis[j.first]) {
					continue;
				}
				if (dis[i] * 2 > dis[R] && dis[j.first] * 2 < dis[R]) {
					long long int minus = takahashi[j.first] * aoki[i];
					minus %= MOD;
					minus *= minus;
					minus %= MOD;
					ans += MOD;
					ans -= minus;
					ans %= MOD;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dis[i] + aoki_dis[i] == dis[R] && dis[i] == aoki_dis[i]) {
			long long int minus = takahashi[i] * aoki[i];
			minus %= MOD;
			minus *= minus;
			minus %= MOD;
			ans += MOD;
			ans -= minus;
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}