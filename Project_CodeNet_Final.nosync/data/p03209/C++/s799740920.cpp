#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const long double PI = acos(-1);
 
ll rec(int n, ll x) {
	if (n == 0) {
		return 1;
	}
	
	ll len = (1LL << (n + 1)) - 3;
	ll num = (1LL << n) - 1;
 
	if (x == 1) {
		return 0;
	}
	else if (x <= len + 1) {
		return rec(n - 1, x - 1);
	}
	else if (x <= len + 2) {
		return num + 1;
	}
	else if(x <= (len + 1) * 2) {
		return num + 1 + rec(n - 1, x - len - 2);
	}
	else {
		return num * 2 + 1;
	}
}
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/
 
	int n;
    ll x;
	cin >> n >> x;
 
	out(rec(n, x));
 
	return 0;
}