#include "bits/stdc++.h"
#define Rep(i,n) for(int i=0;i<(int)(n);i++)
#define For(i,n1,n2) for(int i=(int)(n1);i<(int)(n2);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=((ll)(n)-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(ll)(n1);i<(ll)(n2);i++)
#define RFOR(i,n1,n2) for(ll i=((ll)(n1)-1);i>=(ll)(n2);i--)
#define all(a)  (a).begin(),(a).end()
#define IOS std::cin.tie(0),std::ios::sync_with_stdio(false)

namespace idaten {

	using namespace std;
	using ll = int_fast64_t;
	using ull = uint_fast64_t;
	using P = std::pair<int64_t, int64_t>;
	template<typename T1, typename T2> inline bool chmin(T1& a, T2 b) { if (a > b) { a = b; return 1; }return 0; }
	template<typename T1, typename T2> inline bool chmax(T1& a, T2 b) { if (a < b) { a = b; return 1; }return 0; }
	template<class Type>struct is_vector : std::false_type {};
	template<class ValueType, class Alloc>struct is_vector<std::vector<ValueType, Alloc>> : std::true_type {};
	template <typename T> inline std::ostream& operator << (std::ostream& out, const std::vector<T>& v) {
		if (v.empty())return out;
		constexpr bool is_vector_v = is_vector<T>::value;
		if (is_vector_v)for (auto itr = v.begin(); itr != v.end();)out << (*itr), out << ((++itr != v.end()) ? "\n" : "");
		else for (auto itr = v.begin(); itr != v.end();)out << (*itr), out << ((++itr != v.end()) ? " " : "");
		return out;
	}
	inline void put() {}
	template<class T> inline void put(const T& first) { std::cout << first << "\n"; }
	template<class T, class... N> inline void put(const T& first, const N& ... rest) { std::cout << first << " "; put(rest...); }
	inline void putn() {}
	template<class T, class... N> inline void putn(const T& first, const N& ... rest) { std::cout << first << "\n"; putn(rest...); }

	vector<int> demical(ll n, int k, int l = -1) {
		vector<int> rtn;
		if (l < 0) {
			while (n > 0) {
				rtn.push_back(n % k);
				n /= k;
			}
		} else {
			rtn.resize(l);
			REP(i, l) {
				rtn[i] = n % k;
				n /= k;
			}
		}
		return rtn;
	}

	ll naive(ll n, vector<ll>& a) {
		ll b = 1ll << n;
		ll res = LLONG_MIN;
		REP(i, b) {
			auto v = demical(i, 2, n);
			bool flag = true;
			ll tmp = 0;
			int cnt = 0;
			REP(j, n) {
				if (j < n - 1 && (v[j] && v[j + 1])) {
					flag = false;
					break;
				}
				if (v[j]) {
					tmp += a[j];
					cnt++;
				}
			}
			if (flag&&cnt==n/2) {
				chmax(res, tmp);
			}
			
		}
		return res;
	}

	void solve() {
		IOS;
		int n;
		cin >> n;
		vector<ll> a(n);
		REP(i, n) {
			cin >> a[i];
		}
		ll res = LLONG_MIN;
		if (n % 2 == 0) {
			/*ll tmp = 0;
			REP(i, n / 2) {
				tmp += a[i * 2];
			}
			chmax(res, tmp);
			tmp = 0;
			REP(i, n / 2) {
				tmp += a[i * 2 + 1];
			}
			chmax(res, tmp);*/
			vector<ll> fe(n / 2 + 1, 0), fo(n / 2 + 1, 0);
			vector<ll> be(n / 2 + 1, 0), bo(n / 2 + 1, 0);
			vector<ll> ff(n / 2 + 1, 0), bb(n / 2 + 1, 0);
			REP(i, n) {
				int t = i / 2;
				if (i % 2 == 0) {
					fe[t + 1] = fe[t] + a[i];
				} else {
					fo[t + 1] = max(fo[t] + a[i], fe[t] + a[i]);;
				}
			}
			/**for (int i = 0; i < n; i += 2) {
				ll tmp = 0;
				tmp += max(fe[i / 2], fo[i / 2]);
				tmp += max(be[i / 2], bo[i / 2]);
				chmax(res, tmp);
			}*/
			chmax(res, max(fe.back(), fo.back()));

		} else {
			//vector<ll> ev(n / 2,0), od(n / 2,0);
			vector<ll> fe(n / 2 + 1, 0), fo(n / 2 + 1, 0);
			vector<ll> be(n / 2 + 1, 0), bo(n / 2 + 1, 0);
			vector<ll> ff(n / 2 + 1, 0), bb(n / 2 + 1, 0);
			REP(i, n-1) {
				int t = i / 2;
				if (i % 2 == 0) {
					fe[t + 1] = fe[t] + a[i];
				} else {
					fo[t + 1] = max(fo[t] + a[i], fe[t] + a[i]);;
				}
			}
			/*REP(i, n / 2 + 1) {
				ll t1 = fe[i];
				ll t2 = fb.
				ff[i] = 
			}*/
			/*ev[0] = a[0];
			for (int i = 2; i/2 < n/2; i += 2) {
				ev[i / 2] = ev[i / 2 - 1] + a[i];
			}*/
			vector<ll> b(n);
			REP(i, n) {
				b[i] = a[i];
			}
			reverse(all(b));
			REP(i, n - 1) {
				int t = i / 2;
				if (i % 2 == 0) {
					be[t + 1] = be[t] + b[i];
				} else {
					bo[t + 1] = max(bo[t] + b[i], be[t] + b[i]);;
				}
			}
			reverse(all(be));
			reverse(all(bo));
			for (int i = 0; i < n; i += 2) {
				ll tmp = 0;
				tmp += max(fe[i / 2], fo[i / 2]);
				tmp += max(be[i / 2], bo[i / 2]);
				chmax(res, tmp);
			}
			/*od[0] = b[0];
			for (int i = 2; i/2 < n/2; i += 2) {
				ev[i / 2] = ev[i / 2 - 1] + a[i];
			}
			for (int i = 0; i < n; i += 2) {
				chmax(res, ev[i / 2] + od[n/2-1- i / 2]);
			}*/
			/*if (n == 3) {
				res = *max_element(all(a));
			} else {
				vector<ll> s(3, 0);
				REP(i, 3) {
					ll tmp = 0;
					for (int j = i; j < n - 3 + i; j += 2) {
						tmp += a[i];
					}
					s[i] = tmp;
				}
				ll tmp = 0;
				tmp = s[0];
				chmax(res, tmp + a[n - 3]);
				chmax(res, tmp + a[n - 2]);
				chmax(res, tmp + a[n - 1]);
				tmp = s[1];
				chmax(res, tmp + a[n - 2]);
				chmax(res, tmp + a[n - 1]);
				tmp = s[2];
				chmax(res, tmp + a[n - 1]);
			}*/
			
		}
		put(res);
		//return res;
	}
	
} // namespace idaten

int main() {
	idaten::solve();
	//idaten::hoge();
	return 0;
}