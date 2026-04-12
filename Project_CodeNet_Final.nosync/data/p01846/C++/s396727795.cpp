#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,N) for(ll i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100

ll sq(ll num) { return num*num; }
ll mod_pow(ll x, ll n) {
	if (n == 0)return 1;
	if (n == 1)return x%MOD;
	ll res = sq(mod_pow(x, n / 2));
	res %= MOD;
	if (n % 2 == 1) {
		res *= x;
		res %= MOD;
	}
	return res;
}
ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return a*b % MOD; }

vector<vector<bool>> cht(string s) {
	vector<vector<bool>> res;
	vector<bool> buf;
	rep(i, s.size()) {
		if (s[i] == 'b')buf.push_back(1);
		else if (s[i] == '/') {
			res.push_back(buf);
			buf.clear();
		}
		else {
			rep(j, s[i] - '0')buf.push_back(0);
		}
	}
	res.push_back(buf);
	return res;
}

string chs(vector<vector<bool>> t) {
	string res;
	rep(i, t.size()) {
		ll cnt = 0;
		rep(j, t[i].size()) {
			if (t[i][j]) {
				string ss = "0";
				if (cnt != 0) {
					ss[0] += cnt;
					res += ss;
				}
				res += "b";
				cnt = 0;
			}
			else cnt++;
		}
		string ss = "0";
		if (cnt != 0) {
			ss[0] += cnt;
			res += ss;
		}
		if (i != t.size() - 1)res += "/";
	}
	return res;
}

string s;

int main() {
	while (cin >> s&&s != "#") {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		c--;
		d--;
		vector<vector<bool>> tt = cht(s);
		tt[a][b] = 0;
		tt[c][d] = 1;
		cout << chs(tt) << endl;
	}
}