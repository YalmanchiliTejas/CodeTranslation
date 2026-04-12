//「全て0ならa_i点」と言い換えると見通しが良い。（重複カウントに気を使わなくて良いため）
//1の場所を決めていく。貰うDPを考えると見通しが良い。便宜上、0文字目, N+1文字目に1を置くことにすると見通しが良い。
//a[i][j] = dp[j] + cost(j, i)をメモリ節約で持つ形式。(for i -> for j)
//a[i][j] -> a[i+1][j]の更新は, r = iの区間[l, r]について処理する感じ。一様加算クエリになる。
//dp[i] = min(a[i][0],a[i][1],…,a[i][i-1])なので、これは区間minクエリになる。
//よって、a([i])[j]をセグメント木（StarrySky木）で持てば良い。

#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

const int DEPTH = 18;
const int INF = 1e+15;
struct StarrySky {
	int addVal[1 << (DEPTH + 1)];
	int minVal[1 << (DEPTH + 1)];
	
	StarrySky() {
		int i;
		for (i = 0; i < (1 << (DEPTH + 1)); i++) {
			addVal[i] = 0;
			minVal[i] = 0;
		}
	}
	
	//[l, r)
	void add(int l, int r, int v, int a = 0, int b = (1 << DEPTH), int id = 0) {
		if (a >= r || b <= l) return;
		if (l <= a && b <= r) { addVal[id] += v; minVal[id] += v; return; }
		add(l, r, v, a, a + (b - a) / 2, id * 2 + 1);
		add(l, r, v, a + (b - a) / 2, b, id * 2 + 2);
		minVal[id] = min(minVal[id * 2 + 1], minVal[id * 2 + 2]) + addVal[id];
	}
	
	//[l, r)
	int getMin(int l, int r, int a = 0, int b = (1 << DEPTH), int id = 0) {
		if (a >= r || b <= l) return INF;
		if (l <= a && b <= r) return minVal[id];
		int res1 = getMin(l, r, a, a + (b - a) / 2, id * 2 + 1);
		int res2 = getMin(l, r, a + (b - a) / 2, b, id * 2 + 2);
		return min(res1, res2) + addVal[id];
	}
	
	int get(int pos) {
		pos += (1 << DEPTH) - 1;
		int ret = addVal[pos];
		while (pos > 0) {
			pos = (pos - 1) / 2;
			ret += addVal[pos];
		}
		return ret;
	}
	
	void update(int pos, int x) {
		int res = get(pos);
		add(pos, pos + 1, x - res);
	}
};

int n, m;
vector<int> lefts[200001];	//lefts[i][j] = 「右端 = iになっている区間の左端」, 閉区間で考える
vector<int> scores[200001];
StarrySky dp;

signed main() {
	int i, j;
	int sumA = 0;
	
	cin >> n >> m;
	rep(i, m) {
		int l, r, a;
		cin >> l >> r >> a;
		sumA += a;
		lefts[r].push_back(l);
		scores[r].push_back(a);
	}
	
	//dp[0] = 0;
	REP(i, 1, n + 1) {
		int res = dp.getMin(0, i);
		dp.update(i, res);
		rep(j, lefts[i].size()) {
			int l = lefts[i][j];
			int a = scores[i][j];
			dp.add(0, l, a);
		}
	}
	
	int ans1 = dp.getMin(0, n + 1);
	cout << sumA - ans1 << endl;
	return 0;
}