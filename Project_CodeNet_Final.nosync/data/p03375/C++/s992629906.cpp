#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 3e3 + 5;
int comb[MAX][MAX], memo[MAX][MAX];

inline int add(int a, int b, int mod) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
	return a;
}

inline int sub(int a, int b, int mod) {
	a -= b;
	if(0 > a) {
		a += mod;
	}
	return a;
}

inline int mult(int a, int b, int mod) {
	return (1LL * a * b) % mod;
}

inline int f_exp(int x, int exp, int mod) {
	if(exp == 0) {
		return 1;
	}
	else if(exp & 1) {
		return mult(x, f_exp(x, exp - 1, mod), mod);
	}
	return f_exp(mult(x, x, mod), exp / 2, mod);
}

inline int phi(int x) {
	return x - 1;
}

int S(int n, int k, const int &mod) {
	if(k > n) {
		return 0;
	}
	else if(n == 0 && k == 0) {
		return 1;
	}
	else if(k == 0) {
		return 0;
	}

	int &ans = memo[n][k];
	if(~ans) {
		return ans;
	}

	ans = add(mult(k, S(n - 1, k, mod), mod), S(n - 1, k - 1, mod), mod);
	return ans;
}

inline int kernel(int n, int k, int mod) {
	return add(mult(k + 1, S(n, k + 1, mod), mod), S(n, k, mod), mod);
}

int n;
int ways(int x, int mod) {
	int total = 1;
	fori(i, 1, x + 1) {
		int cur = mult(kernel(x, i, mod), f_exp(2, (n - x) * i, mod), mod);

		total = add(total, cur, mod);
	}

	total = mult(total, f_exp(2, f_exp(2, n - x, phi(mod)), mod), mod);

	return total;
}

int main() {
	memset(memo, -1, sizeof memo);

	int mod;
	scanf("%d %d", &n, &mod);

	fori(i, 0, MAX) {
		fori(j, 0, i + 1) {
			if(i == j || j == 0) {
				comb[i][j] = 1;
			}
			else {
				comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1], mod);
			}
		}
	}

	int ans = 0;

	fori(i, 0, n + 1) {
		int cur = mult(comb[n][i], ways(i, mod), mod);

		if(i % 2 == 0) {
			ans = add(ans, cur, mod);
		}
		else {
			ans = sub(ans, cur, mod);
		}
	}

	printf("%d\n", ans);

	return 0;
}
