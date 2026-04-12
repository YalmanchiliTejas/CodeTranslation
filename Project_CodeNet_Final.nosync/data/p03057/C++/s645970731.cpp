#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define P 1000000007

#define N 200010
int f[N], g[N];

int n, m;
string s;

int main() {
	cin >> n >> m >> s;
	if (s[0] == 'B') {
		for (int i = 0; i < m; i ++)
			s[i] = 'R' + 'B' - s[i];
	}
	if (s == string(m, 'R')) {
		int fbb = 1, fbr = 0, frb = 0, frr = 1;
		for (int i = 1; i < n; i ++) {
			int gbb = fbr;
			int gbr = (fbb + fbr)%P;
			int grb = frr;
			int grr = (frr + frb)%P;
			fbb = gbb;
			fbr = gbr;
			frb = grb;
			frr = grr;
		}
		int S = ((ll)frr + fbr + frb)%P;
		cout << S << endl;
		return 0;
	}
	if (n%2 == 1) {
		puts ("0");
		return 0;
	}

	int l = n;
	for (int i = 0; i < m; ) {
		int j = i;
		while (j < m && s[j] == s[i]) j++;
		if (j == m) break;
		if ((j-i)%2 == 1) {
			if (s[i] == 'R') l = min(l, j-i);
		} else {
			if (i == 0) l = min(l, j+1);
		}
		i = j;
	}

	l = (l+1)/2;
	n /= 2;

	f[0] = 1;
	g[1] = 1;
	for (int i = 1; i <= n; i ++) {
		if (i <= l) f[i] = g[i]; else {
			f[i] = (g[i] - g[i-l]+P)%P;
		}
		g[i+1] = (g[i] + f[i])%P;
	}

	int S = 0;
	for (int i = 0; i < min(l, n); i ++) {
		int T = (g[n-i] - g[n-l]+P)%P;
		// f[n-i-1] + .. + f[n-l];
		(S += T) %= P;
	}

	S = (ll)S*2%P;
	cout << S << endl;
	return 0;
}
