#include <bits/stdc++.h>

const int MAXN = 51;
typedef long long LL;
LL A[MAXN]; int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n; LL tc = 0;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	while (true) {
		int at = std::max_element(A + 1, A + 1 + n) - A;
		if (A[at] < n) break;
		LL t = A[at] / n; tc += t;
		for (int i = 1; i <= n; ++i) if (i != at) A[i] += t;
		A[at] %= n;
	}
	std::cout << tc << std::endl;
	return 0;
}
