#include <bits/stdc++.h>
using namespace std;

const int N = 3003, S = 3003, mod = 998244353;
int n, s, a, f[S], fp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for(int i = 1; i <= n; ++i) {
		cin >> a;
		if(a > s) continue;
		f[0] = i;
		(fp += (long long)f[s - a] * (n - i + 1) % mod) %= mod;
		for(int j = s - 1; j >= a; --j) {
			(f[j] += f[j - a]) %= mod;
		}
	}
	cout << fp << endl;
	return 0;
}
