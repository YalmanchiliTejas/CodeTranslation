#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using VE = vector<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
ll size(int n) {
	if (n == 0) return 1;
	else return size(n - 1) * 2 + 3;
}
ll pathi(int n) {
	if (n == 0) return 1;
	else return pathi(n - 1) * 2 + 1;
}
ll calc(int n, ll x) {
	if (x == 0) return 0;
	if (n == 0) return 1;
	if (x < 2 + size(n - 1)) return calc(n - 1, x - 1);
	else if (x == 2 + size(n - 1)) return pathi(n - 1) + 1;
	else if (x > 2 + size(n - 1)) return pathi(n - 1) + 1 + calc(n - 1, x - size(n - 1) - 2);
}
int main() {
	int n; ll x;
	cin >> n >> x;
	cout << calc(n, x) << endl;
	return 0;
}