#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
#define rep_r(i,s,n)for(ll i=n-1;i>=s;i--)
#define repe_r(i,s,n)for(ll i=s;i<=n;i++)
static const ll MOD = 1e9 + 7;
static const ll MAX_L = (ll)1 << 62;

bool B[100002] = {};
bool T[100002] = {};
int main() {
	ll n; cin >> n;
	string s; cin >> s;

	rep(i, 0, s.size()) {
		B[i] = (s[i] == 'o');
	}

	B[n] = B[0];
	B[n + 1] = B[1];

	rep(k, 0, 4) {
		if (k == 0) {
			T[0] = 1; T[1] = 1;
		}
		else if (k == 1) {
			T[0] = 1; T[1] = 0;
		}
		else if (k == 2) {
			T[0] = 0; T[1] = 1;
		}
		else if (k == 3) {
			T[0] = 0; T[1] = 0;
		}

		rep(i, 2, n + 2) {
			if (B[i - 1]) {
				if (T[i - 2] && T[i - 1]) T[i] = 1;
				else if (!T[i - 2] && T[i - 1]) T[i] = 0;
				else if (T[i - 2] && !T[i - 1]) T[i] = 0;
				else if (!T[i - 2] && !T[i - 1]) T[i] = 1;
			}
			else {
				if (T[i - 2] && T[i - 1]) T[i] = 0;
				else if (!T[i - 2] && T[i - 1]) T[i] = 1;
				else if (T[i - 2] && !T[i - 1]) T[i] = 1;
				else if (!T[i - 2] && !T[i - 1]) T[i] = 0;
			}
		}

		if (T[0] == T[n] && T[1] == T[n + 1]) {
			rep(i, 0, n) {
				cout << (T[i] ? 'S' : 'W');
			}
			cout << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}