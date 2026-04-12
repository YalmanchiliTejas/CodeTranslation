#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n-1;i>=0;i--)
#define rep_re(i,s,n)for(int i = n;i>=0;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_M = 100001;

int main() {
	ll n, k; cin >> n >> k;
	ll ans = 0;
	if (k == 0) {
		cout << n * n << endl;
		return 0;
	}
	repe(b, k + 1, n) {
		ans += n / b * (b - k) + max((ll)0, ((n % b) - k + 1));
	}
	cout << ans << endl;
	return 0;
}