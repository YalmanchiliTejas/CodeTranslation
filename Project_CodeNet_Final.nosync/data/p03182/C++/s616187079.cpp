#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cstring>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 200005;
//////////////////////////////

Int n, m, l, r, a;
vector<P> interval[N];

struct Seg {
	vector<Int> sum;
	vector<Int> mx;
	Seg() {
		sum.resize(1 << 19, 0);
		mx.resize(1 << 19, 0);
	}

	void add_val(Int l, Int r, Int val, Int bottom = 0, Int top = 1 << 18, Int pos = 1)
	{
		if (l <= bottom && top <= r) {
			sum[pos] += val;
			return;
		}
		if (r <= bottom || top <= l) {
			return;
		}
		Int mid = (bottom + top) / 2;
		add_val(l, r, val, bottom, mid, pos * 2);
		add_val(l, r, val, mid, top, pos * 2 + 1);
		mx[pos] = max(mx[pos * 2] + sum[pos * 2], mx[pos * 2 + 1] + sum[pos * 2 + 1]);
	}

	Int max_val(int l, int r, int bottom = 0, int top = 1 << 18, int pos = 1)
	{
		if (l <= bottom && top <= r) {
			return sum[pos] + mx[pos];
		}
		if (r <= bottom || top <= l) {
			return -LINF;
		}
		Int mid = (bottom + top) / 2;
		return max(max_val(l, r, bottom, mid, pos * 2), max_val(l, r, mid, top, pos * 2 + 1)) + sum[pos];
	}
};


int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> a;
		interval[r].push_back(P(l, a));
	}

	Seg seg;

	for (Int i = 1; i <= n; i++) {
		Int mx = seg.max_val(0, i);
		seg.add_val(i, i + 1, mx);
		for (auto p : interval[i]) {
			Int l = p.first;
			Int a = p.second;
			seg.add_val(l, i + 1, a);
		}
	}

	cout << seg.max_val(0, n + 1) << endl;

	return 0;
}
