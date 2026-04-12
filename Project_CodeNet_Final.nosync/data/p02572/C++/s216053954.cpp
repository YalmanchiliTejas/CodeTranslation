	#include <iostream>
	#include <stdio.h>
	#include <cmath>
	#include <algorithm>
	#include <climits>
	#include <vector>
	#include <iomanip>
	#include <string>
	#include <queue>
	#include <numeric>
	#include <functional>
	#include <array>
	#include <map>
	#include <set>

	#define INF 1000000007 //1000000000000000003
	#define MOD 1000000007
	#define MAX 2000005

	#define ll long long
	#define rep(i,n) for (int i = 0; i < (n); ++i)

	//printf("%.10f", );
	//cout << fixed << setprecision(10) << heikin << endl;
	//vector<vector<int>> data(3, vector<int>(4, -1));
	//left + 1 < top

	using namespace std;
	using P = pair<ll, ll>;
	using Pc = pair<double, int>;
	using T = tuple<int, int, int>;
	using edge = struct { int to; long long dist; };
	const double PI = 3.141592653589793;
	long long fact[MAX], inv[MAX];
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };

	//////////////////////////////////

	vector<vector<int>> bingo(3, vector<int>(3));
	vector<vector<int>> tree(100005);
	int color[100005];
	map<P, int>colorMap;
	int m = 0;

	struct Connection {
		vector<int>connect;
		int parent = INF;
		int dep = INF;
		Connection() {}
	};

	bool compare_by_second(pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		else {
			return a.first < b.first;
		}
	}

	struct UnionFind {
		vector<int>uf;

		UnionFind(int size) :uf(size, -1) {};

		int root(int target) {
			if (uf[target] < 0)return target;
			else return uf[target] = root(uf[target]);
		}

		void merge(int a, int b) {
			a = root(a);
			b = root(b);
			if (a == b)return;
			if (uf[b] < uf[a])swap(a, b);
			uf[a] += uf[b];
			uf[b] = a;
		}
	};

	ll CalcPow(ll num, ll power) {
		if (power == 0)return 1;
		if (power % 2 == 0) {
			ll half = CalcPow(num, power / 2);
			return (half * half) % MOD;
		}
		else return (num * CalcPow(num, power - 1)) % MOD;
	}

	ll combination(ll all, ll select) {
		if (all < select) return 0;
		if (all < 0 || select < 0) return 0;
		return fact[all] * (inv[select] * inv[all - select] % MOD) % MOD;
	}

	void initCombination(int max) {
		fact[0] = fact[1] = 1;
		for (int i = 2; i <= max; ++i) {
			fact[i] = fact[i - 1] * i % MOD;
		}

		inv[max] = CalcPow(fact[max], MOD - 2);
		for (int i = max - 1; 0 <= i; --i) {
			inv[i] = (inv[i + 1] * (i + 1)) % MOD;
		}
	}

	ll getGcd(ll a, ll b) {
		if (a < b) {
			ll temp = b;
			b = a;
			a = temp;
		}

		ll r;
		while ((r = a % b) != 0) {
			a = b;
			b = r;
		}
		return b;
	}

	/*int getNum(ll target) {

	int bottom = 0;
	int top = 151;
	while (1 < top - bottom) {
	int middle = (top + bottom) / 2;
	if (target < line[middle])top = middle;
	else bottom = middle;
	}
	return bottom;
	}*/

	/*
	void dfs(int depth, int next, int parent) {
	++depth;
	for (int c : connection[next].connect) {
	if (c == parent)continue;
	if (depth < connection[c].dep) {
	if (connection[c].dep == INF)co++;
	connection[c].dep = depth;
	connection[c].parent = next;
	}
	else if (connection[c].parent == next) {
	continue;
	}
	dfs(depth, c, next);
	}
	}*/
	/*
	int N, M, Q;
	int mx = 0;
	int abcd[55][4];

	void calc(vector<int> A, int current){
	if (A.size() == N) {
	int sum = 0;
	for (int i = 0; i < Q; ++i) {
	if (A[abcd[i][1]] - A[abcd[i][0]] == abcd[i][2])sum += abcd[i][3];
	}
	mx = max(mx, sum);
	return;
	}
	for (int i = current; i <= M; ++i) {
	A.push_back(i);
	calc(A, i);
	A.pop_back();
	}
	}*/

	enum Color {
		Red,
		Green,
		None,
	};

	using PC = pair<int, Color>;

	string getString(ll num) {
		int iNum = (int)num;
		//1->a , 26->z
		if (num == 0)iNum += 26;
		iNum += 96;
		char c = int(iNum);
		string rS = "c";
		rS[0] = c;
		return rS;
	}

	int solve(int current, int x, int n) {
		if (n == 1)return 1;
		if (x < (n * current))return current;
		solve(n * current, x, n);
	}

	int main() {

		int n; cin >> n;
		vector<ll> a(n);
		ll all = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			all += a[i];
		}

		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			ll tNum = all - a[i];
			tNum %= MOD;
			ans += tNum * a[i] % MOD;
			ans %= MOD;
			all -= a[i];
		}

		cout << ans << endl;
	}
	


