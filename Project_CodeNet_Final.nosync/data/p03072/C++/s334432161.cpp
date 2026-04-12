#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> P;
constexpr ll mod = 1000000007;
int main() {
	int n;
	cin >> n;
	vll h(n);
	ll ma = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		if (ma <= h[i])
			ans++;
		ma = max(ma, h[i]);
	}
	
	cout << ans;
}