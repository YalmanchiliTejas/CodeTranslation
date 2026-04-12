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
				fct[0] = 1;
				for (int i = 1; i < sz; i++) fct[i] = mul(fct[i - 1], i);
				fnv[sz - 1] = inv(fct[sz - 1]);
				for (int i = sz - 1; i >= 1; i--) fnv[i - 1] = mul(fnv[i], i);
			}
		inline void add (int& a, const int b) const {
			a += b;
			if (a >= md) a -= md;
		}
		inline void sub (int& a, const int b) const {
			a -= b;
			if (a < 0) a += md;
		}
		template<class... A> int mul (A... args) const {
			long long ret = 1;
			for (int a : std::initializer_list<int>{args...}) {
				ret *= a;
				ret %= md;
			}
			return (int)ret;
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
		inline int div (int a, int b) const {
			return mul(a, inv(b));
		}
		inline int binom (int n, int k) const {
			assert(0 <= n && n < sz);
			if (k < 0 || n < k) return 0;
			return mul(fct[n], fnv[k], fnv[n - k]);
		}
};
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int h, w, k;
	cin >> h >> w >> k;
	finite_field fld(1e9 + 7, h * w + 1);
	auto solve = [&] (int h, int w, int k) {
		int ret = 0, denom = 0;
		for (int i = 1; i < h; i++) {
			fld.add(ret, fld.mul(i, h - i));
			fld.add(denom, i);
		}
		ret = fld.mul(ret, w, w);
		denom = fld.mul(denom, w, w);
		fld.add(denom, fld.mul(h, fld.binom(w, 2)));
		ret = fld.div(ret, denom);
		return ret;
	};
	int ret = 0;
	fld.add(ret, solve(h, w, k));
	fld.add(ret, solve(w, h, k));
	ret = fld.mul(ret, fld.binom(k, 2));
	ret = fld.mul(ret, fld.binom(h * w, k));
	cout << ret << endl;
	return 0;
}