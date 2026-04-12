
#include<bits/stdc++.h>

using namespace std;

/*helpfull*/
using vl  = vector<long long>;
using vpl = vector<pair<long long, long long>>;
using vs = vector<string>;
using pl  = pair<long long, long long>;
using ll  = long long int;
using vb  = vector<bool>;


struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1> {}(p.first);
		auto hash2 = hash<T2> {}(p.second);
		return hash1 ^ hash2;
	}
};
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// shortcut macros
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp              make_pair
#define fi              first
#define se              second
// #define mt              make_tuple
#define pb              push_back
#define all(x)          (x).begin(), (x).end()
#define ini(a, v)       memset(a, v, sizeof(a))
#define rep(i, a, n)    for(ll i=a ; i<n ; ++i)
#define For(i, n)       rep(i, 0, n)
#define sz(x)           (int((x).size()))
#define ump(x,y)        unordered_map<x,y>
#define umpr(x,y,z)     unordered_map<x,y,z>
void printcase(ll &x) {
	cout << "Case #" << x << ": ";
}
void read(vector<ll>&v, ll &n) {
	For(i, n)
	cin >> v[i];
}
void read(ll &x) {
	cin >> x;
}
void read(string &s) {
	cin >> s;
}
void read(int &x) {
	cin >> x;
}
void read(ll a[], ll &n) {
	For(i, n)
	cin >> a[i];
}
void print() {
	cout << endl;
}
void write(vector<ll>&v, ll &n) {
	For(i, n)
	cout << v[i] << " ";
	cout << endl;
}
void write(vector<ll>&v) {
	ll n = v.size();
	For(i, n)
	cout << v[i] << " ";
	cout << endl;
}
void write(ll x) {
	cout << x << endl;
}
void write(string &s) {
	cout << s << endl;
}
void write(int &x) {
	cout << x << endl;
}
void write(ll a[], ll &n) {
	For(i, n)
	cout << a[i] << " ";
	cout << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOS;
	ll x;
	cin >> x;
	if (x < 30)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}


