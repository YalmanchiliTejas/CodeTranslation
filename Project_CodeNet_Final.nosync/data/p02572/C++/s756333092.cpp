//#pragma GCC optimize "trapv"
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define fios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define M_PI 3.14159265358979323846
typedef long long ll;



int main() {
	int n;
	ll mod = 1e9 + 7;
	cin >> n;
	vector<ll> a(n);
	for(auto& x: a) cin >> x;

	ll sm = a[0], ans = 0;
	for(int i = 1; i < n; i++) {
		ans = (ans + sm * a[i]) % mod;
		sm = (sm + a[i]) % mod;
	}
	cout << ans << endl;
}