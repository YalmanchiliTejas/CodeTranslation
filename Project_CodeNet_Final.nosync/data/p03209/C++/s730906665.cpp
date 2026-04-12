#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll len[50], pat[50];

ll patties(int n, ll x) {
	if (n == 0) {
		if (x <= 0) return 0;
		else return 1;
	} else if (x <= 1 + len[n-1]) {
		return patties(n-1, x-1);
	} else {
		return pat[n-1] + 1 + patties(n-1, x - 2 - len[n-1]);
	}
}

int main() {
	
	int N;  ll X; cin >> N >> X;
	len[0] = 1; pat[0] = 1; // because order 0 burger is just "P"
	for (int i = 1; i < N; i++) {
		len[i] = len[i-1] * 2 + 3; // B + order i-1 burger + P + order i-1 burger + B
		pat[i] = pat[i-1] * 2 + 1; // order i-1 burger + P + order i-1 burger
	}

	cout << patties(N, X);
	return 0;
}