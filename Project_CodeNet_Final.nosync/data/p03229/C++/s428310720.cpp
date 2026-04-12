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
ll solve(int n, deque<ll> dq) {
	ll res = 0;
	ll prev = dq.front();
	ll prev2 = prev;
	ll l = -1;
	dq.pop_front();
	bool b = true;
	while (dq.size() != 2) {
		if (b) {
			res += abs(prev - dq.back());
			prev = dq.back();
			dq.pop_back();
		}
		else {
			res += abs(prev - dq.front());
			prev = dq.front();
			dq.pop_front();
		}
		b ^= true;
	}
	res += max(abs(prev - dq.front()) + abs(prev2 - dq.back()), abs(prev - dq.back()) + abs(prev2 - dq.front()));
	return res;
}
int main() {
	int n;
	cin >> n;
	V a(n);
	deque<ll> dq;
	deque<ll> dq2;
	rep(i, n) {
		cin >> a[i];
	}
	if (n == 2) {
		cout << abs(a[0] - a[1]) << endl;
		return 0;
	}
	sort(all(a));
	rep(i, n) {
		dq.push_back(a[i]);
		dq2.push_front(a[i]);
	}
	cout << max(solve(n, dq), solve(n, dq2)) << endl;
	return 0;
}