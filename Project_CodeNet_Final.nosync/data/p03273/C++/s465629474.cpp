#include <bits/stdc++.h>
using namespace std;

#define mem(arr, i) fill(arr, arr + sizeof(arr), i)
#define MEM(arr, i) memset(arr, i, sizeof(arr))
#define Push push_back
#define Pair make_pair
#define ALL(x) x.begin(), x.end()
#define X first
#define Y second
#define ACCEL ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef unsigned long long ull;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<pll,lli> p3l;
typedef vector<int> vcI;
typedef vector<lli> vcL;
typedef vector<pii> vPI;
typedef vector<pll> vPL;
typedef vector<p3l> v3L;
typedef vector<vcL> vvL;
//typedef priority_queue<T> prior_S<T>;
//typedef priority_queue< T, vector<T>, greater<T> > prior_B<T>;
const double PI = 3.141592653589793;
const lli I_MAX = 1LL << 60;
      lli   mod = 1000000007;

/// templates ///

const lli maxN = 2E5;

vcL inv(maxN+5, 1);
vcL fac(maxN+5, 1);

void ADD(lli &x, lli y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
}

void MUL(lli &x, lli y) {
	x *= y;
	x = (x % mod + mod) % mod;
}

lli mypow(lli b, lli e) {
	lli ans = 1;
	while (e) {
		if (e & 1) MUL(ans, b);
		MUL(b, b);
		e >>= 1;
	}
	return ans;
}

lli modinv(lli n) {
	return mypow(n, mod - 2);
}

void calcInv(lli n) {
	for (int i = 2; i <= n; ++i) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
}

void calcFac(lli n) {
	for (int i = 2; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % mod;
	}
}

lli cm(lli a, lli b) {
	lli ans = 1;
	if (a < b) return 0;

	MUL(ans, inv[fac[a - b]]);
	MUL(ans, inv[fac[b]]);
	MUL(ans, fac[a]);

	return ans;
}

lli Lucas(lli n, lli m) {
	if (m == 0) return 1;
	return cm(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}

lli doLucas(lli n, lli m) {
	calcInv(mod);
	calcFac(mod);
	return Lucas(n, m);
}

/// coding area ///

const lli maxn = 1E5;

void precal() {

	return;
}

void solve() {
	lli n, m;
	cin >> n >> m;
	
	string str[n];
	for (auto &x : str) cin >> x;
	
	bool h[m], w[n];
	memset(h, false, sizeof(h));
	memset(w, false, sizeof(w));
	
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			if (str[i][j] == '.') {
				++cnt;
			}
		}
		
		if (cnt == m) {
			w[i] = true;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (str[j][i] == '.') {
				++cnt;
			}
		}
		
		if (cnt == n) {
			h[i] = true;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (w[i] or h[j]);
			else cout << str[i][j];
		}
		cout << '\n';
	}
}

int main() {
	precal();
	int t = 1;
	#ifdef LOCAL
		t = INT_MAX;
	#else
		ACCEL;
	#endif
//	cin >> t;
	for (int i = 1; i <= t; ++i) {
//		printf("Case #%d: ", i );
		solve();
	}
	return 0;
}

