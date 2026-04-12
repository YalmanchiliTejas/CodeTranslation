#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

ll n;
string s;

bool func(V m) {
	rep(i, n - 2) {
		if (m[i + 1] == 1) {
			if (s[i + 1] == 'o') {
				m[i + 2] = m[i];
			}
			else {
				m[i + 2] = -m[i];
			}
		}
		else {
			if (s[i + 1] == 'o') {
				m[i + 2] = -m[i];
			}
			else {
				m[i + 2] = m[i];
			}
		}
	}
	if (m[n - 1] == 1) {
		if (s[n - 1] == 'o') {
			if (m[n - 2] == 1 && m[0] == 1) {
				if ((s[0] == 'o' && m[1] == 1) ||
					(s[0] == 'x' && m[1] == -1)) {
					rep(i, n) {
						if (m[i] == 1) {
							cout << 'S';
						}
						else {
							cout << 'W';
						}
					}
					cout << "\n";
					return true;
				}
			}
			else if (m[n - 2] == -1 && m[0] == -1) {
				if ((s[0] == 'o' && m[1] == -1) ||
					(s[0] == 'x' && m[1] == 1)) {
					rep(i, n) {
						if (m[i] == 1) {
							cout << 'S';
						}
						else {
							cout << 'W';
						}
					}
					cout << "\n";
					return true;
				}
			}
		}
		else {
			if (m[n - 2] == 1 && m[0] == -1) {
				if ((s[0] == 'o' && m[1] == -1) ||
					(s[0] == 'x' && m[1] == 1)) {
					rep(i, n) {
						if (m[i] == 1) {
							cout << 'S';
						}
						else {
							cout << 'W';
						}
					}
					cout << "\n";
					return true;
				}
			}
			else if (m[n - 2] == -1 && m[0] == 1) {
				if ((s[0] == 'o' && m[1] == 1) ||
					(s[0] == 'x' && m[1] == -1)) {
					rep(i, n) {
						if (m[i] == 1) {
							cout << 'S';
						}
						else {
							cout << 'W';
						}
					}
					cout << "\n";
					return true;
				}
			}
		}
	}
	else {
		if (s[n - 1] == 'x') {
			if (m[n - 2] == 1 && m[0] == 1) {
				if ((s[0] == 'o' && m[1] == -1) ||
					(s[0] == 'x' && m[1] == 1)) {
					rep(i, n) {
						if (m[i] == 1) {
							cout << 'S';
						}
						else {
							cout << 'W';
						}
					}
					cout << "\n";
					return true;
				}
			}
			else if (m[n - 2] == -1 && m[0] == -1) {
				if ((s[0] == 'o' && m[1] == 1) ||
					(s[0] == 'x' && m[1] == -1)) {
					rep(i, n) {
						if (m[i] == 1) {
							cout << 'S';
						}
						else {
							cout << 'W';
						}
					}
					cout << "\n";
					return true;
				}
			}
		}
		else {
			if (m[n - 2] == 1 && m[0] == -1) {
				if ((s[0] == 'o' && m[1] == 1) ||
					(s[0] == 'x' && m[1] == -1)) {
					rep(i, n) {
						if (m[i] == 1) {
							cout << 'S';
						}
						else {
							cout << 'W';
						}
					}
					cout << "\n";
					return true;
				}
			}
			else if (m[n - 2] == -1 && m[0] == 1) {
				if ((s[0] == 'o' && m[1] == -1) ||
					(s[0] == 'x' && m[1] == 1)) {
					rep(i, n) {
						if (m[i] == 1) {
							cout << 'S';
						}
						else {
							cout << 'W';
						}
					}
					cout << "\n";
					return true;
				}
			}
		}
	}

	return false;
}

void solve_abc_d() {
	ll x;
	ll k;
	cin >> n;

	cin >> s;
	V m;
	
	m = V(n, 0);
	m[0] = 1;
	m[1] = 1;
	if (func(m)) {
		return;
	}

	m = V(n, 0);
	m[0] = 1;
	m[1] = -1;
	if (func(m)) {
		return;
	}

	m = V(n, 0);
	m[0] = -1;
	m[1] = 1;
	if (func(m)) {
		return;
	}

	m = V(n, 0);
	m[0] = -1;
	m[1] = -1;
	if (func(m)) {
		return;
	}

	cout << -1 << "\n";
	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(7);

	solve_abc_d();

	return 0;
}
