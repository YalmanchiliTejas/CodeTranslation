#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())



struct StarrySkyTree {
	int n;
	std::vector<long long> segv, segAdd;
	void add(int a, int b, long long  x, int k, int l, int r) {
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			segAdd[k] += x;
			return;
		}
		int m = (l + r) / 2;
		add(a, b, x, 2 * k + 1, l, m);
		add(a, b, x, 2 * k + 2, m, r);
		segv[k] = std::max(segAdd[2 * k + 1] + segv[2 * k + 1], segAdd[2 * k + 2] + segv[2 * k + 2]);
	}
	long long max(int a, int b, int k, int l, int r)const {
		if (r <= a || b <= l)return LLONG_MIN;
		if (a <= l && r <= b) {
			return segv[k] + segAdd[k];
		}
		int m = (l + r) / 2;
		return segAdd[k] + std::max(max(a, b, 2 * k + 1, l, m), max(a, b, 2 * k + 2, m, r));
	}
public:
	StarrySkyTree(int n = 1 << 18) {
		init(n);
	}
	void init(int n) {
		this->n = n;
		segv.assign(2 * n - 1, 0);
		segAdd.assign(2 * n - 1, 0);
	}
	void add(int a, int b, long long x) {//[a,b)にxを加算
		add(a, b, x, 0, 0, n);
	}
	long long max(int a, int b)const {//[a,b)の最大値
		return max(a, b, 0, 0, n);
	}
};




int n, m;
int l[200000];
int r[200000];
int a[200000];
vector<pair<int, int >> in[200001];
vector<pair<int, int >> out[200001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m;
	rep(i, m) {
		cin >> l[i] >> r[i] >> a[i];
	}
	rep(i, m) {
		in[l[i]].emplace_back(r[i], a[i]);
		out[r[i]].emplace_back(l[i], a[i]);
	}

	StarrySkyTree segtree;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (const auto &p : in[i]) {
			segtree.add(0, i, p.second);
		}

		auto v = segtree.max(0, i);
		ans = max(ans, v);
		segtree.add(i, i + 1, v);

		for (const auto &p : out[i]) {
			segtree.add(0, p.first, -p.second);
		}
	}
	cout << ans << endl;




	return 0;
}
