#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n, k;
	cin >> n >> k;

	if (k == 0) {
		cout << (ll) n * n << endl;
		return 0;
	}
	ll ans = 0;
	for (int b = 1; b <= n; b++) {
		if (b - k <= 0) continue;
		ll num = n / b;
		ans += (ll)num * (b - k);
		ans += max(0, n % b - k + 1);
	}

	cout << ans << endl;
	return 0;
}