#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define rep_r(i,s,n)for(ll i=n-1;i>=s;i--)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
#define repe_r(i,s,n)for(ll i=s;i<=n;i++)

ll x[500000];
ll s = 250000;
ll e = 250001;
int main() {
	ll n; cin >> n;
	repe(i, 1, n) {
		ll a; cin >> a;
		if (i & 1) {
			x[s] = a;
			s--;
		}
		else {
			x[e] = a;
			e++;
		}
	}

	if (n & 1) {
		rep(i, s + 1, e) {
			cout << x[i];
			if (i != e - 1) {
				cout << " ";
			}
		}
	}
	else {
		rep_r(i, s + 1, e) {
			cout << x[i];
			if (i != s) {
				cout << " ";
			}
		}
	}

	cout << endl;
	return 0;
}