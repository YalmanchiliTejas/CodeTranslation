#include<bits/stdc++.h>
using namespace std;
string to_string(const string& s) {
	return '"' + s + '"';
}
string to_string(const bool b) {
	return (b ? "true" : "false");
}
string to_string(const char* s) {
	return to_string((string)s);
}
string to_string(const char c) {
	string s = "'";
	s += c;
	s += "'";
	return s;
}
template<class T, class U>
string to_string(const pair<T, U>& p) {
	string s = "(";
	s += to_string(p.first);
	s += ", ";
	s += to_string(p.second);
	s += ")";
	return s;
}
template<class T>
string to_string(const T& a) {
	bool first = true;
	string s = "{";
	for (const auto& x : a) {
		if(!first){
			s += ", ";
		}
		first = false;
		s += to_string(x);
	}
	s += "}";
	return s;
}
void debug_out() {cerr << '\n';}
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int inf = 1e9 + 100;
const ll inf64 = 7e18l;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	string s;
	int k = 0;
	cin >> s >> k;
	int n = s.size();
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k + 2, vector<ll>(2)));
	dp[0][0][1] = 1;
	int f = s[0] - '0';
	dp[0][1][1] = f - 1;
	dp[0][1][0] = 1;
	for (int i = 0; i < n - 1; ++i) {
		//i -> i + 1
		int next = s[i + 1] - '0';
		for (int now = 0; now <= 9; ++now) {
			for (int kk = 0; kk <= k; ++kk) {
				for (bool sm : {0, 1}) {
					if (sm == 0 && now > next) {
						continue;
					}
					int new_k = (now == 0 ? kk : kk + 1);
					int new_sm = -1;
					if (now < next) {
						new_sm = 1;
					} else {
						new_sm = sm;
					}
					dp[i + 1][new_k][new_sm] += dp[i][kk][sm];
				}
			}
		}
		//~ for (int kk = 0; kk <= k; ++kk) {
			//~ dp[i + 1][kk + 1][1] += dp[i][kk][1] * 9;
			//~ dp[i + 1][kk][1] += dp[i][kk][1];
			//~ dp[i + 1][kk + 1][1] += dp[i][kk][0] * (next - 1);
			//~ if (next != 0) {
				//~ dp[i + 1][kk][1] += dp[i][kk][0];
			//~ }
			//~ if (next != 0) {
				//~ dp[i + 1][kk + 1][0] += dp[i][kk][0];
			//~ } else {
				//~ dp[i + 1][kk][0] += dp[i][kk][0];
			//~ }
		//~ }
	}
	cout << dp[n - 1][k][0] + dp[n - 1][k][1] << '\n';
 	return 0;
}
