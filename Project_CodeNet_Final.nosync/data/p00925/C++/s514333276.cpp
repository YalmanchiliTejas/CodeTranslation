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

string s;
int num;

ll number(string& s, ll& i);
ll term(string& s, ll& i);
ll factor(string& s, ll& i);
ll expr(string& s, ll& i);

ll number(string& s, ll& i) {
	ll n = s[i++] - '0';
	while (isdigit(s[i])) n = n * 10 + s[i++] - '0';
	return n;
}

ll factor(string& s, ll& i) {
	if (isdigit(s[i])) return number(s, i);
	i++;
	ll ret = expr(s, i);
	i++;
	return ret;
}

ll term(string& s, ll& i) {
	ll val = factor(s, i);
	while (s[i] == '*' || s[i] == '/') {
		char op = s[i];
		i++;
		int val2 = factor(s, i);
		if (op == '*') val *= val2;
		else val /= val2;
	}
	return val;
}

ll expr(string& s, ll& i) {
	ll val = term(s, i);
	while (s[i] == '+' || s[i] == '-') {
		char op = s[i];
		i++;
		int val2 = term(s, i);
		if (op == '+') val += val2;
		else val -= val2;
	}
	return val;
}

int main() {
	cin >> s >> num;
	ll pos = 0;
	ll m = expr(s, pos);
	ll l = s[0] - '0';
	for (int i = 1; i < s.size(); i += 2) {
		if (s[i] == '+')l += s[i + 1] - '0';
		else l *= s[i + 1] - '0';
	}
	if (m == num) {
		if (l == num)cout << "U" << endl;
		else cout << "M" << endl;
	}
	else if (l == num)cout << "L" << endl;
	else cout << "I" << endl;
}