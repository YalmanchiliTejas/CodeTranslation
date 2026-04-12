// Copyright (C) 2018 Skqliao. All rights served.
#include <bits/stdc++.h>

#define rep(i, l, r) for (__typeof(l) i = (l), _##i##_ = (r); i < _##i##_; ++i)
#define rof(i, l, r) for (__typeof(l) i = (l) - 1, _##i##_ = (r); i >= _##i##_; --i)
#define irep(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) static_cast<int>((x).size())
typedef long long ll;
typedef std::pair<int, int> pii;
template<typename T> inline bool chkMin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkMax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int N, K;

int main() {
	scanf("%d%d", &N, &K);
	if(K == 0) {
		printf("%lld\n", (ll)N * N);
		return 0;
	}
	ll res = 0;
	rep(i, K + 1, N + 1) {
		res += (N / i) * (i - K);
		if(N % i >= K) {
			res += N % i - K + 1;
		}
	}
	printf("%lld\n", res);
	return 0;
}