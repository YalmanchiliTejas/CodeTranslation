
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define m0(x) memset(x,0,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define int long long

using namespace std;


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };




ll gcd(ll x, ll y) {
	ll m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}

ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}

long long nCr(int n, int r) {
	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}


const int MOD = 1000000007;


char ans[100010];
signed main() {
	int N;
	string s;
	cin >> N >> s;
	char last;


	ans[0] = 'S', ans[1] = 'S';
	if (s[0] == 'o')last = 'S';
	else last = 'W';
	FOR(i,2, N) {
		if (s[i - 1] == 'o') {
			if (ans[i - 1] == 'S') {
				if (ans[i - 2] == 'S')ans[i] = 'S';
				else ans[i] = 'W';
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
		}
		else if(s[i-1]=='x') {
			if (ans[i - 1] == 'S') {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'S';
				else ans[i] = 'W';
			}
		}
	}
	if (last == ans[N - 1]) {
		if (s[N - 1] == 'o') {
			if (ans[N - 1] == 'S') {
				if (ans[N - 2] == ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
			else {
				if (ans[N - 2] != ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
		}
		else {
			if (ans[N - 1] == 'S') {
				if (ans[N - 2] != ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
			else {
				if (ans[N - 2] == ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
		}

	}

	ans[0] = 'S', ans[1] = 'W';
	if (s[0] == 'o')last = 'W';
	else last = 'S';
	FOR(i, 2, N) {
		if (s[i - 1] == 'o') {
			if (ans[i - 1] == 'S') {
				if (ans[i - 2] == 'S')ans[i] = 'S';
				else ans[i] = 'W';
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
		}
		else if (s[i - 1] == 'x') {
			if (ans[i - 1] == 'S') {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'S';
				else ans[i] = 'W';
			}
		}
	}
	if (last == ans[N - 1]) {
		if (s[N - 1] == 'o') {
			if (ans[N - 1] == 'S') {
				if (ans[N - 2] == ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
			else {
				if (ans[N - 2] != ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
		}
		else {
			if (ans[N - 1] == 'S') {
				if (ans[N - 2] != ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
			else {
				if (ans[N - 2] == ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
		}
	}

	ans[0] = 'W', ans[1] = 'S';
	if (s[0] == 'o')last = 'W';
	else last = 'S';
	FOR(i, 2, N) {
		if (s[i - 1] == 'o') {
			if (ans[i - 1] == 'S') {
				if (ans[i - 2] == 'S')ans[i] = 'S';
				else ans[i] = 'W';
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
		}
		else if (s[i - 1] == 'x') {
			if (ans[i - 1] == 'S') {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'S';
				else ans[i] = 'W';
			}
		}
	}
	if (last == ans[N - 1]) {
		if (s[N - 1] == 'o') {
			if (ans[N - 1] == 'S') {
				if (ans[N - 2] == ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
			else {
				if (ans[N - 2] != ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
		}
		else {
			if (ans[N - 1] == 'S') {
				if (ans[N - 2] != ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
			else {
				if (ans[N - 2] == ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
		}
	}


	ans[0] = 'W', ans[1] = 'W';
	if (s[0] == 'o')last = 'S';
	else last = 'W';
	FOR(i, 2, N) {
		if (s[i - 1] == 'o') {
			if (ans[i - 1] == 'S') {
				if (ans[i - 2] == 'S')ans[i] = 'S';
				else ans[i] = 'W';
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
		}
		else if (s[i - 1] == 'x') {
			if (ans[i - 1] == 'S') {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'S';
				else ans[i] = 'W';
			}
		}
	}
	if (last == ans[N - 1]) {
		if (s[N - 1] == 'o') {
			if (ans[N - 1] == 'S') {
				if (ans[N - 2] == ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
			else {
				if (ans[N - 2] != ans[0]) {
					REP(i, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
		}
		else {
			if (ans[N - 1] == 'S') {
				if (ans[N - 2] != ans[0]) {
					REP(i, N) {
						cout << ans[i];

					}
					return 0;
				}
			}
			else {
				if (ans[N - 2] == ans[0]) {
					REP(i, N) {
						cout << ans[i];
					}
					return 0;
				}
			}
		}
	}
		cout << -1 << endl;
		return 0;
}


