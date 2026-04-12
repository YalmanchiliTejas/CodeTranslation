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
		template<class... A> int sum (A... args) const {
			int ret = 0;
			for (int a : initializer_list<int>{args...}) {
				add(ret, a);
			}
			return ret;
		}
		template<class... A> int prod (A... args) const {
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
		int ans = 0;
		for (int first = 0; first < 2; first++) {
			vector<int> dp(2, 0);
			dp[first] = 1;
			for (int i = 1; i < n; i++) {
				vector<int> new_dp(2, 0);
				for (int j = 0; j < 2; j++) {
					for (int x = 0; x < 2; x++) {
						if (j + x < 2) {
							fld.add(new_dp[j], dp[x]);
						}
					}
				}
				swap(dp, new_dp);
			}
			for (int j = 0; j < 2; j++) {
				if (j + first < 2) {
					fld.add(ans, dp[j]);
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (n & 1) {
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
	int ans = 0;
	if (bound == 0) {
		ans = 1;
	} else {
		vector<int> dp(n);
		vector<int> pref(n + 1);
		dp[0] = 1;
		pref[1] = 1;
		for (int i = 1; i < n; i++) {
			dp[i] = pref[i];
			if (i - bound - 1 >= 0) {
				fld.sub(dp[i], pref[i - bound - 1]);
			}
			pref[i + 1] = fld.sum(pref[i], dp[i]);
		}
		for (int i = n - 1 - bound; i < n; i++) {
			fld.add(ans, fld.prod(dp[i], n - i));
		}
	}
	cout << fld.prod(2, ans) << endl;
	return 0;
}