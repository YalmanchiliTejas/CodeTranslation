// in the name of Allah

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define ll long long
#define double long double
#define sz(x) ((int) (x.size()))

#define fr first
#define se second

#define inf 1e9
#define max_n 123456
#define mod 1000000007

ll add(ll a, ll b) {
	a += b;
	if(a >= mod) return a - mod;
	return a;
}

ll mul(ll a, ll b) {
	a *= b;
	if(a >= mod) return a % mod;
	return a;
}

ll power(ll a, ll b) {
	ll p = 1;
	while(b) {
		if(b&1) p = mul(p, a);
		a = mul(a, a);
		b /= 2;
	}
	return p;
}

int n, d;
string s;
ll dp[10001][101][2];

ll memo(int idx, int rem, int eq) {
	if(idx == n) {
		if(rem == 0) return 1;
		return 0;
	}
	if(dp[idx][rem][eq] != -1) return dp[idx][rem][eq];
	ll res = 0;
	if(eq == 0) {
		for(int i=0; i<10; i++) {
			res = add(res, memo(idx+1, (rem + i)%d, 0));
		}
	}
	else {
		res = memo(idx+1, (rem + s[idx]-'0')%d, 1);
		for(int i=0; i<s[idx]-'0'; i++) {
			res = add(res, memo(idx+1, (rem + i)%d, 0));
		}
	}
	return dp[idx][rem][eq] = res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> d;
	n = sz(s);
	memset(dp, -1, sizeof dp);
	cout << add(memo(0, 0, 1), mod-1) << endl;
	return 0;
}