#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n-1;i>=s;i--)
#define repe_r(i,s,n)for(int i = n;i>=s;i--)

ll a[100001] = {};

int main() {
	ll n; cin >> n;
	repe(i, 1, n) cin >> a[i];

	multiset<ll> s;
	for (ll i = 1; i <= n; ++i) {
		auto itr = s.lower_bound(a[i]);
		if (itr != s.begin()) {
			s.erase(--itr);
		}
		s.insert(a[i]);
	}
	cout << s.size() << endl;
	return 0;
}