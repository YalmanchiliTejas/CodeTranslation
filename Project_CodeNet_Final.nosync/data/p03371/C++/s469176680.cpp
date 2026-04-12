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

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	ll ans = 100000000000000;
	for (int i = 0; i <= 200000; i++) {
		ll now = 0;
		now = i * c;
		now += max(0, x - i / 2) * a + max(0, y - i / 2) * b;
		chmin(ans, now);
	}

	cout << ans << endl;
	return 0;
}