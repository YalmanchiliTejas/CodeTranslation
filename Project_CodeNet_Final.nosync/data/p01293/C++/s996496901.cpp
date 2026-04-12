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
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

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

char t;
string c[4][13];

int func(char c) {
	if (c == 'T')return 10;
	else if (c == 'J')return 11;
	else if (c == 'Q')return 12;
	else if (c == 'K')return 13;
	else if (c == 'A')return 14;
	return c - '0';
}

int main() {
	while (cin >> t&&t != '#') {
		rep(i, 4)rep(j, 13)cin >> c[i][j];
		int cnt[2] = {};
		int w = 0;
		rep(i, 13) {
			bool f = 0;
			int MAX = func(c[w][i][0]);
			char s = c[w][i][1];
			rep(j, 4) {
				if (c[j][i][1] == s) {
					if (!f || s == t) {
						if (MAX < func(c[j][i][0])) {
							w = j;
							MAX = func(c[j][i][0]);
						}
					}
				}
				else if (c[j][i][1] == t) {
					if (f) {
						if (MAX < func(c[j][i][0])) {
							w = j;
							MAX = func(c[j][i][0]);
						}
					}
					else {
						f = 1;
						w = j;
						MAX = func(c[j][i][0]);
					}
				}
			}
			cnt[w % 2]++;
		}
		if (cnt[0] > cnt[1])cout << "NS " << cnt[0] - 6 << endl;
		else cout << "EW " << cnt[1] - 6 << endl;
	}
}