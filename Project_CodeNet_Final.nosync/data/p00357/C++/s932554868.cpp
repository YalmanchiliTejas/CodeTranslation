#include<iostream>
#include<vector>

using namespace std;

int N;
int nobi[300000 + 10];

struct LazySegmentTree {
private:
	int n;
	vector<int> node, lazy;

public:
	LazySegmentTree(vector<int> v) {
		int sz = (int)v.size();
		n = 1; while (n < sz) n *= 2;
		node.resize(2 * n - 1);
		lazy.resize(2 * n - 1, 0);

		for (int i = 0; i<sz; i++) node[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--) node[i] = node[i * 2 + 1] + node[i * 2 + 2];
	}
	// k 番目のノードについて遅延評価を行う
	void eval(int k, int l, int r) {

		// 遅延配列が空でない場合、自ノード及び子ノードへの
		// 値の伝播が起こる
		if (lazy[k] != 0) {
			node[k] += lazy[k];

			// 最下段かどうかのチェックをしよう
			// 子ノードは親ノードの 1/2 の範囲であるため、
			// 伝播させるときは半分にする
			if (r - l > 1) {
				lazy[2 * k + 1] += lazy[k] / 2;
				lazy[2 * k + 2] += lazy[k] / 2;
			}

			// 伝播が終わったので、自ノードの遅延配列を空にする
			lazy[k] = 0;
		}
	}
	void add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;

		// k 番目のノードに対して遅延評価を行う
		eval(k, l, r);

		// 範囲外なら何もしない
		if (b <= l || r <= a) return;

		// 完全に被覆しているならば、遅延配列に値を入れた後に評価
		if (a <= l && r <= b) {
			lazy[k] += (r - l) * x;
			eval(k, l, r);
		}

		// そうでないならば、子ノードの値を再帰的に計算して、
		// 計算済みの値をもらってくる
		else {
			add(a, b, x, 2 * k + 1, l, (l + r) / 2);
			add(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = node[2 * k + 1] + node[2 * k + 2];
		}
	}
	int getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		if (b <= l || r <= a) return 0;

		// 関数が呼び出されたら評価！
		eval(k, l, r);
		if (a <= l && r <= b) return node[k];
		int vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;
	}

};

LazySegmentTree dp(vector<int>(300000 + 10)), dp2(vector<int>(300000 + 10));

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nobi[i];
		nobi[i] /= 10;
	}

	dp.add(0, 1, 1);
	for (int i = 0; i < N - 1; i++) {
		if (dp.getsum(i, i + 1) && nobi[i] > 0) {
			dp.add(i + 1, i + nobi[i] + 1, 1);
		}
	}
	if (!dp.getsum(N - 1, N)) {
		cout << "no" << endl;
		return 0;
	}
	dp2.add(N - 1, N, 1);
	for (int i = N - 1; i >= 0; i--) {
		if (dp2.getsum(i, i + 1) && nobi[i] > 0) {
			dp2.add(i - nobi[i], i, 1);
		}
	}
	if (!dp2.getsum(0, 1)) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}
	return 0;
}
