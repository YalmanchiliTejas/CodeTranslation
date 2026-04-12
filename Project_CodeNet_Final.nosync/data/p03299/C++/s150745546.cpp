#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "vector"
#include "string"
#include "map"
#include "algorithm"
#include "functional"
#include "set"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007; 

long long int N, M, K, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

struct Node {
	int l;
	int r;
	int bottom = 0;
	int up;
};

void Search(vector<long long int>&dp1, vector<long long int>& dp2, vector<vector<int>>&edge, vector<Node> &node, int n = M - 1) {
	if (edge[n].empty()) {
		dp1[n] = power(2, node[n].up - node[n].bottom, MOD);
		dp2[n] = dp1[n];
		dp2[n] += power(2, node[n].r - node[n].l + 1, MOD) + MOD - 2;
		dp2[n] %= MOD;
		return;
	}
	dp1[n] = 1;
	dp2[n] = 1;
	int w = node[n].r - node[n].l + 1;
	for (auto i : edge[n]) {
		if (dp1[i] == -1)Search(dp1, dp2, edge, node, i);
		dp1[n] *= dp1[i];
		dp1[n] %= MOD;
		dp2[n] *= (dp1[i] + dp2[i]) % MOD;
		dp2[n] %= MOD;
		/*if(node[i].r!=node[i].l)*/w -= node[i].r - node[i].l + 1;
	}
	dp2[n] *= power(2, w, MOD);
	dp2[n] %= MOD;
	dp2[n] += dp1[n] * (power(2, node[n].up - node[n].bottom, MOD) - 2);
	dp2[n] %= MOD;
	dp1[n] *= power(2, node[n].up - node[n].bottom, MOD);
	dp1[n] %= MOD;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	set<int>s;
	for (auto i : v)s.insert(i);
	vector<Node>node;
	for (auto i : s) {
		L = -1;
		for (int j = 0; j < N; j++) {
			if (v[j] >= i) {
				if (L == -1)L = j;
			}
			else {
				if (L != -1) {
					Node n;
					n.l = L;
					n.r = j - 1;
					L = -1;
					n.up = MOD;
					for (int k = n.l; k <= n.r; k++) {
						n.up = min(n.up, v[k]);
					}
					if (n.up == i)	node.push_back(n);
				}
			}
		}
		if (L != -1) {
			Node n;
			n.l = L;
			n.r = N - 1;
			n.up = MOD;
			for (int k = n.l; k <= n.r; k++) {
				n.up = min(n.up, v[k]);
			}
			if (n.up == i)	node.push_back(n);
		}
	}
	M = node.size();
	//cout << M << endl;
	vector<vector<int>>edge(M);
	reverse(node.begin(), node.end());
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			if (node[i].l >= node[j].l&&node[i].r <= node[j].r) {
				edge[j].push_back(i);
				node[i].bottom = node[j].up;
				break;
			}
		}
	}
	vector<long long int>dp1(M, -1);
	vector<long long int>dp2(M, -1);
	Search(dp1, dp2, edge, node);
	cout << dp2.back() << endl;
	return 0;
}