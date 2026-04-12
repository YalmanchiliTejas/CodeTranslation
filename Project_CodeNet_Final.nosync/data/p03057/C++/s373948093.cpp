#include <bits/stdc++.h>
using namespace std;
class finite_field {
	const int md;
	const int sz;
	vector<int> fct, fnv;
	public :
		finite_field(
				const int md,
				const int init_factorial_size = 0
			) :
			md(md), sz(init_factorial_size),
			fct(sz), fnv(sz)
			{
				if (sz) {
					fct[0] = 1;
					for (int i = 1; i < sz; i++) fct[i] = prod(fct[i - 1], i);
					fnv[sz - 1] = inv(fct[sz - 1]);
					for (int i = sz - 1; i >= 1; i--) fnv[i - 1] = prod(fnv[i], i);
				}
			}
		inline void add (int& a, const int b) const {
			a += b;
			if (a >= md) a -= md;
		}
		inline void sub (int& a, const int b) const {
			a -= b;
			if (a < 0) a += md;
		}
		template<class... A> inline int sum (A... args) const {
			int ret = 0;
			for (int a : initializer_list<int>{args...}) {
				add(ret, a);
			}
			return ret;
		}
		inline int dif (int a, int b) const {
			sub(a, b);
			return a;
		}
		template<class... A> inline int prod (A... args) const {
			long long ret = 1;
			for (int a : initializer_list<int>{args...}) {
				ret *= a;
				ret %= md;
			}
			return (int)ret;
		}
		void mul (int& a, int b) const {
			a = prod(a, b);
		}
		inline int inv (int a) const {
			a %= md; if (a < 0) a += md;
			int b = md, u = 0, v = 1;
			while (a) {
				int t = b / a;
				b -= a * t; swap(a, b);
				u -= v * t; swap(u, v);
			}
			assert(b == 1);
			if(u < 0) u += md;
			return u;
		}
		inline int quat (int a, int b) const {
			return prod(a, inv(b));
		}
		void div (int& a, int b) const {
			a = quat(a, b);
		}
		inline int pow (int a, long long b) {
			int ret = 1;
			for (; b; b >>= 1) {
				if (b & 1) mul(ret, a);
				a = prod(a, a);
			}
			return ret;
		}
		inline int binom (int n, int k) const {
			assert(0 <= n && n < sz);
			if (k < 0 || n < k) return 0;
			return prod(fct[n], fnv[k], fnv[n - k]);
		}
};
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int n, m; string s;
	cin >> n >> m >> s;
	finite_field fld(1e9 + 7);
	if (s == string(m, s[0])) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			fld.add(dp[i], dp[i - 1]);
			fld.add(dp[i], dp[i - 2]);
		}
		int ret = 0;
		fld.add(ret, dp[n]);
		fld.add(ret, fld.prod(dp[n - 1], 2));
		cout << ret << endl;
		return 0;
	}
	if (n % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> seqs;
	int t = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] == s[0]) {
			++t;
		} else {
			seqs.push_back(t);
			t = 0;
		}
	}
	int bound = seqs[0];
	if (!(bound & 1)) {
		++bound;
	}
	for (int it = 1; it < (int) seqs.size(); it++) {
		if (seqs[it] % 2 == 1) {
			bound = min(bound, seqs[it]);
		}
	}
	n /= 2;
	bound /= 2;
	int ret = 0;
	if (bound == 0) {
		ret = 1;
	} else {
		vector<int> dp(n + 1);
		dp[1] = 1;
		for (int i = 1; i < n; i++) {
			dp[i + 1] = fld.prod(2, dp[i]);
			if (i - bound - 1 >= 0) {
				fld.sub(dp[i + 1], dp[i - bound - 1]);
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			fld.sub(dp[i + 1], dp[i]);
		}
		for (int i = n - 1 - bound; i < n; i++) {
			fld.add(ret, fld.prod(dp[i + 1], n - i));
		}
	}
	cout << fld.prod(2, ret) << endl;
	return 0;
}