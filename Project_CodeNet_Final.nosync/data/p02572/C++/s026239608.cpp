#include <bits/stdc++.h>
using namespace std;
string to_string(string s)
{
	return '"' + s + '"';
}

string to_string(const char *s)
{
	return to_string((string)s);
}

string to_string(bool b)
{
	return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v)
{
	bool first = true;
	string res = "{";
	for (const auto &x : v)
	{
		if (!first)
		{
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}


void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(x...) ;
#endif
const long long mod = 1000000007 ;
void solve() {
	int n ;
	cin >> n ;
	vector<int> arr(n) ;
	for (int i = 0 ; i < n ; ++i) {
		cin >> arr[i] ;
	}
	long long ans = 0 ;
	vector<long long> prefix(n) ;
	prefix[0] = arr[0] ;
	for (int i = 1 ; i < n ; ++i)
		prefix[i] = (prefix[i - 1] + arr[i]) % mod ;
	for (int i = 0 ; i < n ; ++i)
		ans += (arr[i] % mod * (prefix[n - 1]  - prefix[i] + mod) % mod ) % mod ;

	cout << ans % mod ;

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin) ;
#endif
	int T = 1 ;
	while (T--) {
		solve() ;
	}
}