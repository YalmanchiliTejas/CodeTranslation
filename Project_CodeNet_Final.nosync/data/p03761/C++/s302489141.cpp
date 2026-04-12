#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
#define rep_r(i,s,n)for(ll i=n-1;i>=s;i--)
#define repe_r(i,s,n)for(ll i=s;i<=n;i++)
static const ll MOD = 1e9 + 7;
static const ll MAX_L = (ll)1 << 62;

ll c[50][26] = {};
int main() {
	ll n; cin >> n;
	rep(i, 0, n) {
		string s; cin >> s;
		rep(j, 0, s.size()) {
			c[i][s[j] - 'a']++;
		}
	}

	rep(i, 0, 26) {
		ll minV = 1 << 21;
		rep(k, 0, n) {
			minV = min(c[k][i], minV);
		}
		rep(v, 0, minV) {
			cout << (char)(i + 'a');
		}
	}
	cout << endl;
	return 0;
}