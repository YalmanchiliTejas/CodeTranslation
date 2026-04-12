#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
const int N = 2e5 + 7;
const ll mod = 998244353;

int main() {
	fastIO;
	ll n, x, m;
	cin >> n >> x >> m;
	map<ll, int> first;
	set<ll> seen;
	ll prev = x;
	seen.insert(x);
	first[x] = 1;
	vector<ll> accum = {0, x};
	ll sum = x;
	int st = -1, len = 0;
	for (int i = 2; i <= 2*m+1; i++) {
		ll curr = (prev*prev)%m;
		if (seen.count(curr)) {
			st = first[curr];
			len = i - st;
			break;
		}
		else {
			first[curr] = i;
			seen.insert(curr);
		}
		sum += curr;
		accum.push_back(sum);
		prev = curr;
	}
	ll ans = 0;
	if (n < accum.size()) {
		ans = accum[n];
	}
	else {
		assert(st != -1);
		ans = accum[st-1];
		n -= st-1;
		ans += (n/len) * (accum.back() - accum[st-1]);
		ans += accum[st+(n%len)-1] - accum[st-1];
	}
	cout << ans;

}
