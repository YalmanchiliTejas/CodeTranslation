#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;
list<long long int> Prime(int M) {
	list<long long int>P;
	P.push_back(2);
	P.push_back(3);
	for (int i = 5; i <= M; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	return P;
}
long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H;
long long int ans;

int da[200000];

int root(int x) {
	return da[x] < 0 ? x : da[x] = root(da[x]);
}
bool unionSet(int x, int y) {
	x = root(x); y = root(y);
	if (x != y) {
		if (da[y] < da[x]) swap(x, y);
		da[x] += da[y]; da[y] = x;
	}
	return  x != y;
}
bool findSet(int x, int y) {
	return root(x) == root(y);
}

int size(int x) {
	return -da[root(x)];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	long long int x[100000];
	long long int y[100000];
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		x[i] = x[i] * MOD + i;
		y[i] = y[i] * MOD + i;
	}
	for (int i = 1; i <= N; i++)da[i] = -1;
	sort(x, x + N);
	sort(y, y + N);
	list<long long int>edge[100001];
	for (int i = 0; i < N - 1; i++) {
		int a = x[i] % MOD;
		int b = x[i + 1] % MOD;
		edge[a].push_back((x[i + 1] / MOD - x[i] / MOD)*MOD + b);
		edge[b].push_back((x[i + 1] / MOD - x[i] / MOD)*MOD + a);
		 a = y[i] % MOD;
		 b = y[i + 1] % MOD;
		edge[a].push_back((y[i + 1] / MOD - y[i] / MOD)*MOD + b);
		edge[b].push_back((y[i + 1] / MOD - y[i] / MOD)*MOD + a);
	}
	bool flag[100001] = {};
	flag[0] = true;
	int used = 1;
	priority_queue<long long int, vector<long long int>, greater<long long int>>Q;
	for (auto i : edge[0])Q.push(i);
	while (used<N) {
		long long int a = Q.top();
		Q.pop();
		if (flag[a%MOD])continue;
		used++;
		flag[a%MOD] = true;
		ans += a / MOD;
		for (auto i : edge[a%MOD])Q.push(i);
	}
	cout << ans << endl;
	return 0;
}