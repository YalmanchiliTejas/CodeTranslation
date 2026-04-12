#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll modinv(ll a, ll m) {
	assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}

template <int MOD_> struct modnum {
private:
	int v;
public:
	static const int MOD = MOD_;

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}

	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= (~o);
	}

	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<int(1e9)+7>;


int main(){
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> q;
	for(int i = 0; i < m; i++){
		q.push_back((s[i] == 'R') ^ (s[0] == 'R'));
	}
	int nonzero = 0;
	for(int x : q){
		if(x > 0) nonzero = 1;
	}
	if(!nonzero){
		vector<num> fib = {0, 1};
		while(fib.size() <= n+1){
			fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
		}
		cout << int(fib[n+1] + fib[n-1]) << '\n';
		exit(0);
	}
	int constraint = 1e8;
	int cur = 0;
	int st = 1;
	for(int x : q){
		if(x == 1){
			if(st){
				if(cur % 2 == 1){
					constraint = min(constraint, cur);
				} else {
					constraint = min(constraint, cur + 1);					
				}
			} else {
				if(cur % 2 == 1){
					constraint = min(constraint, cur);
				}
			}
			cur = 0;
			st = 0;
		} else {
			cur += 1;
		}
	}
	if(n & 1){
		cout << 0 << '\n';
		exit(0);
	}
	n /= 2;
	constraint = (constraint + 1) / 2;
	vector<num> dp(n+1, 0);
	vector<num> dpsum(n+1, 0);
	dp[0] = 1;
	dpsum[0] = 1;
	for(int i = 1; i <= n; i++){
		dp[i] = dpsum[i-1];
		if(i-1-constraint >= 0) dp[i] -= dpsum[i-1-constraint];
		dpsum[i] = dpsum[i-1] + dp[i];
	}
	num ans = 0;
	for(int i = 1; i <= constraint; i++){
		if(i <= n){
			ans += dp[n - i] * (2 * i);
		}
	}
	cout << int(ans) << '\n';
}