#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

const int MaxN = 40000 + 5, MaxLen = 670;
const long long Dig = 1000000000000000000;

struct bign {
	int len;
	long long a[MaxLen];
};

inline std::istream& operator >> (std::istream& in, bign &x) {
	std::string str;
	std::cin >> str;
	x.len = (str.length() - 1) / 18 + 1;
	memset(x.a, 0, sizeof x.a);
	for (int i = 0; str[i] != '\0'; ++i) {
		long long d = (str.length() - i - 1) / 18;
		x.a[d] = x.a[d] * 10 + str[i] - '0';
	}
	return in;
}

inline std::ostream& operator << (std::ostream& out, bign x) {
	if (x.len == 0) {
		printf("%lld", 0);
		return out;
	}
	printf("%lld", x.a[x.len - 1]);
	for (int i = x.len - 2; i >= 0; --i)
		printf("%018lld", x.a[i]);
	return out;
}

inline void operator += (bign &x, const bign &y) {
	x.len = std::max(x.len, y.len);
	for (int i = 0; i < x.len; ++i) {
		x.a[i] += y.a[i];
		if (x.a[i] >= Dig) {
			x.a[i + 1]++;
			x.a[i] -= Dig;
		}
	}
	if (x.a[x.len] != 0) x.len++;
}

inline void operator -= (bign &x, const bign &y) {
	for (int i = 0; i < x.len; ++i) {
		x.a[i] -= y.a[i];
		if (x.a[i] < 0) {
			x.a[i] += Dig;
			x.a[i + 1]--;
		}
	}
	while (x.len > 0 && x.a[x.len - 1] == 0) x.len--;
}

inline bool operator == (const bign &x, const bign &y) {
	if (x.len != y.len) return false;
	for (int i = 0; i < x.len; ++i)
		if (x.a[i] != y.a[i]) return false;
	return true;
}

inline bool operator > (const bign &x, const bign &y) {
	if (x.len < y.len) return false;
	if (x.len > y.len) return true;
	for (int i = x.len - 1; i >= 0; --i) {
		if (x.a[i] > y.a[i]) return true;
		if (x.a[i] < y.a[i]) return false;
	}
	return false;
}

int N;
bign X;
bign _0, _1, _2, _3;
bign F[MaxN], G[MaxN];
bign ans, x;

void init() {
	scanf("%d", &N);
	std::cin >> X;

	_0.len = 0;
	_1.len = 1, _1.a[0] = 1;
	_2.len = 1, _2.a[0] = 2;
	_3.len = 1, _3.a[0] = 3;
}

void dfs(int n) {
	if (x == _0) {
		ans = _0;
		return;
	}
	if (n == 0) {
		ans = _1;
		return;
	}

	x -= _1;
	if (x > F[n - 1]) {
		x -= F[n - 1]; x -= _1;
		dfs(n - 1);
		ans += G[n - 1]; ans += _1;
	} else {
		dfs(n - 1);
	}
}

void solve() {
	F[0] = G[0] = _1;
	for (int i = 1; i <= N; ++i) {
		F[i] = F[i - 1];
		F[i] += F[i - 1]; F[i] += _3;
		G[i] = G[i - 1];
		G[i] += G[i - 1]; G[i] += _1;
	}

	x = X;
	dfs(N);
	std::cout << ans << std::endl;
}

int main() {
	init();
	solve();
	return 0;
}