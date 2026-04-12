#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
//#include <numeric> //iota
//#include <sstream>
#include <cstring>
//#include <tuple>
//#include <random>
//#include <string>
//#include <unordered_set>
//#include <bitset>
//#include <unordered_map>
//#include <stack>
#include <cmath>
//#include <deque>
#include <queue>
//#include <list>
#include <array>
using namespace std;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vec vector
#define pb push_back
#define pp pop_back
#define fi first
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define se second
#define un_map unordered_map
#define rep(i,a,n) for (int i = a; i < n; ++i) 
#define inc_rep(i,a,n,inc) for (int i = a; i < n; i += inc) 
#define couts(x) cout << x << "\n" 
#define watch(x) cout << #x << " : " << x << endl;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<long long, long long>  PLII;
template<typename T>
void print(vector<T>& v) {rep(i, 0, (int)v.size()) cout << v[i] << " ";cout << endl;}
int nxt() {int x;cin >> x;return x;}
ll nxtl() {ll x;cin >> x;return x;}
string nxts() {string x;cin >> x;return x;}
double nxtd() {double x; cin >> x; return x;}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll power_mod(ll a, ll b, ll mo) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans % mo * a % mo) % mo;
		}
		a = (a % mo * a % mo) % mo;
		b /= 2;
	}
	return ans;
}
int main() {
	IOS;
	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto &x : v) {
		cin >> x;
	}
	ll const mod = 1e9 + 7; 
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += v[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll z = (sum - v[i])  % mod * v[i] % mod;
		ans = (ans + z) % mod;
	}
	cout << (ans * power_mod(2, mod- 2, mod)) % mod ;
}















	

