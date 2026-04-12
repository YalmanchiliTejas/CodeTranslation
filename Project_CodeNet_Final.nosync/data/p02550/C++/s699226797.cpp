#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
long long n;
int x, m;

int nxt(int a) {
	return (long long) a * a % m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> m;

	map<int, int> seen;
	
	int f = x;
	int clen, cfirst; 

	for (int i = 0; i <= m; i++) {
		if (seen.count(f)) {
			clen = i - seen[f];
			cfirst = f;
			break;
		}

		seen[f] = i;
		f = nxt(f);
	}

	long long ans = 0;

	f = x;
	for (int i = 0; n && i < seen[cfirst]; i++) {
		ans += (long long) f;
		f = nxt(f);
		n -= 1;
	}

	long long cnum = (long long) n / clen;
	long long crem = (long long) n % clen;

	long long sum = 0;

	f = cfirst;
	for (int i = 0; i < clen; i++) {
		if (i == crem) {
			ans += sum;
		}
		sum += f;
		f = nxt(f);
	}

	ans += cnum * sum;

	cout << ans << '\n';

	return 0;
}
