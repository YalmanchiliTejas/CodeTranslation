#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

#define int long long

#define rep(i, n) for (int i=0;i<(int)n;++i)

constexpr int TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); };

const int inf = TEN(18) + 10;

int N, X, D, sum;
int a[55];

int f(int y)
{
	int sousa = 0;

	rep(i, N) sousa += max((a[i] - y) / D, 0ll);

	return sousa;
}

signed main()
{
	cin >> N;

	rep(i, N) {
		cin >> a[i];
	}

	rep(i, N) {
		sum += a[i];
	}

	// X, D を定義する
	X = max(sum - (N - 1) * N, 0ll);
	D = N + 1;

	// はじめに a[i] それぞれに X を足してしまう
	rep(i, N) a[i] += X;

	// 二分探索で f(Y) <= X となる最大の Y を求める(hi = Y となるようにしているつもり) 
	int lo = -1, hi = inf, step = -1;
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;

		if (f(mid) <= X) {
			step = f(mid); // それがf(Y) の値も念のため step に保存しておく
			hi = mid;
		} else {
			lo = mid;
		}
	}

	// わかりやすさのため hi を max_Y とする
	int max_Y = hi;

	rep(i, N) {
		a[i] = a[i] - max((a[i] - max_Y) / D, 0ll) * D;
	}

	// すべての i について a[i] <= N - 1 を満たすまで愚直にシミュレーション
	while (true) {
		bool ok = true;
		rep(i, N) {
			if (a[i] >= N) ok = false;
		}

		if (ok) break;

		int mx = -inf, idx = -1;

		rep(i, N) {
			if (mx < a[i]) {
				mx = a[i];
				idx = i;
			}
		}

		step++;

		if (step > X) {
			a[idx] -= N;

			rep(i, N) if (i != idx) a[i]++;
		} else {
			a[idx] -= D;
		}
	}

	printf("%lld\n", step);
}
