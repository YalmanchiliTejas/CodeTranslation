#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong n;
	vector<llong> h;

	cin >> n;
	llong maxi = 0;
	llong in, ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> in;
		if (i == 0 || in >= maxi)
			ans++;
		maxi = max(maxi, in);
	}

	cout << ans << endl;

	return 0;
}