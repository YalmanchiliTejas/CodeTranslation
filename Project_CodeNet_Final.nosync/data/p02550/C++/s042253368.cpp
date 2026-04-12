#include <bits/stdc++.h>

using namespace std;

void fastio() {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
}

using LL = long long;
using LD = long double;

const LL MOD = 998244353;
const LL INF = LLONG_MAX;
const LL N = 1e6+1;

#define F first
#define S second

int main() {
	fastio();
	
	LL n, x, m;
	cin >> n >> x >> m;

	vector<LL> next(m, -1);
	next[0] = 0;
	next[1] = 1;
	for (LL i = 2; i < m; ++i) {
		LL j = i;
		while (true) {
			LL nx = (j*j)%m;
			next[j] = nx;
			if (nx != -1) {
				break;
			} 
			else {
				j = (j*j) % m;
			}
		}
	}

	LL st = x, cst, sum = 0, len = 0, csum = 0, clen = 0;
	vector<LL> vis(m, 0);

	while (vis[st] == 0) {
		vis[st] = 1;
		len++;
		sum += st;
		st = next[st];
	}

	while (vis[st] == 1) {
		vis[st] = 2;
		clen++;
		csum += st;
		st = next[st];
	}

	LL nsum = sum - csum;
	LL nlen = len - clen;

	LL vst = x, vsum = 0;
	if (nlen > n) {
		for (LL i = 0; i < n; ++i) {
			vsum += vst;
			vst = next[vst];
		}
	}
	else {
		for (LL i = 0; i < nlen; ++i) {
			vsum += vst;
			vst = next[vst];
		}
		n -= nlen;
		vsum += (n/clen)*csum;
		n %= clen;
		for (LL i = 0; i < n; ++i) {
			vsum += vst;
			vst = next[vst];
		}
	}
	cout <<  vsum << "\n";

}