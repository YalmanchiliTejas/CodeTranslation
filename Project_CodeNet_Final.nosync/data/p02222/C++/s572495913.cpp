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
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

void Calculate_Depth(vector<vector<int>>&edge, vector<int>&depth, int stnode) {
	depth[stnode] = 0;
	queue<int>Q;
	Q.push(stnode);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i] > depth[cn] + 1) {
				depth[i] = depth[cn] + 1;
				Q.push(i);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	if (N == 2) {
		cout << 11 << endl;
		return 0;
	}
	vector<int>adis(N, MOD);
	Calculate_Depth(edge, adis, 0);
	int tp = 0;
	for (int i = 1; i < N; i++) {
		if (adis[i] > adis[tp])tp = i;
	}
	vector<int>bdis(N, MOD);
	Calculate_Depth(edge, bdis, tp);
	int bt = 0;
	for (int i = 0; i < N; i++) {
		if (bdis[i] > bdis[bt])bt = i;
	}
	for (auto &i : adis)i = MOD;
	Calculate_Depth(edge, adis, bt);
	vector<int>rdis(N, MOD);
	queue<int>Q;
	for (int i = 0; i < N; i++) {
		if (adis[i] + bdis[i]==adis[tp]) {
			Q.push(i);
			rdis[i] = 0;
		}
	}
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (rdis[i] > rdis[cn]+1) {
				rdis[i] = rdis[cn] + 1;
				Q.push(i);
			}
		}
	}
	int L = 2, R = N;
	while (R - L > 1) {
		int mid = (R + L) / 2;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (!rdis[i])continue;
		//	cout << "mid " << mid << "  " << adis[i] << " " << bdis[i] << endl;
			if (max(adis[i], bdis[i]) >= mid  && rdis[i] * 2 != mid)flag = false;
		}
		if (flag)R = mid;
		else L = mid;
	}
	cout << 11 << string(R - 3, '0') << string(N - R + 1, '1') << endl;
}
