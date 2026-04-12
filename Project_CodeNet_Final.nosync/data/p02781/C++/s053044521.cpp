#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(int i=0;i<(int)(n);i++)
#define For(i,n1,n2) for(int i=(int)(n1);i<(int)(n2);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=((ll)(n)-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(ll)(n1);i<(ll)(n2);i++)
#define RFOR(i,n1,n2) for(ll i=((ll)(n1)-1);i>=(ll)(n2);i--)
#define all(a)  (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()
#define IOS cin.tie(0),ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<ll, ll> P;
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



int main() {
	IOS;
	string s;
	ll k;
	cin >> s >> k;
	ll n = s.size();
	vector<ll> a(n);
	if (n < k) {
		put(0);
		return 0;
	}
	REP(i, n) {
		a[i] = s[i] - '0';
	}
	ll dp[200][200][2];
	REP(i, 200) {
		REP(j, 200) {
			REP(k, 2) {
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	dp[0][1][1] = 1;
	dp[0][0][1] = a[0]-1;
	REP(i, n-1) {
		if (a[i+1] == 0) {
			REP(j, n) {
				dp[i + 1][j + 1][0] += dp[i][j][0];
			}
			
		} else {
			REP(j, n) {
				dp[i + 1][j][0] += dp[i][j][0];
			}
			REP(j, n) {
				dp[i + 1][j + 1][1] += dp[i][j][0];
			}
		}
		REP(j, n) {
			dp[i + 1][j][1] += max(0ll, a[i+1] - 1ll) * dp[i][j][0];
			dp[i + 1][j][1] += dp[i][j][1]*9ll;
			dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	ll res = 0;
	res += dp[n - 1][n - k][0];
	res += dp[n - 1][n - k][1];
	put(res);
	return 0;
}

