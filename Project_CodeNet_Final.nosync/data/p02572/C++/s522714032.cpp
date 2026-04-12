#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b ? "true" : "false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vector<bool> v) {
	string res;
	for(int i = 0; i < (int) v.size(); i++)
		res += char('0' + v[i]);
	return res;
}
 
template<size_t S> string to_string(bitset<S> b) {
	string res;
	for(int i = 0; i < S; i++)
		res += char('0' + b[i]);
	return res;
}

template<class T> string to_string(T v) {
    bool f = 1;
    string res;
    for(auto& x : v) {
		if(!f)
			res += ' ';
		f = 0;
		res += to_string(x);
	}
    return res;
}
 
void DBG() {
	cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}

#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
	int n;
	cin >> n;
	long long mod = 1e9 + 7;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	long long sm = a[0], ans = 0;
	for(int i = 1; i < n; i++){
		(ans += a[i] * sm) %= mod;
		(sm += a[i]) %= mod;
	}
	cout << ans << '\n';
}	
 
int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
 	
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}