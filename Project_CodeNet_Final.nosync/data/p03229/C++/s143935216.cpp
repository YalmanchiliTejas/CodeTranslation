#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	sort(ALL(v), greater<>());
	if (n % 2 == 1) {
		ll ans1 = 0;
		rep(i,n/2) ans1 += 2 * v[i];
		rep(i,2) ans1 -= v[n/2 + i];
		for (int i = n/2 + 2; i < n; i++) ans1 -= 2 * v[i];

		ll ans2 = 0;
		sort(ALL(v));
		rep(i,n/2) ans2 -= 2 * v[i];
		rep(i,2) ans2 += v[n/2 + i];
		for (int i = n/2 + 2; i < n; i++) ans2 += 2 * v[i];

		cout << max(ans1, ans2) << endl;
	} else {
		ll ans = 0;
		rep(i,n/2-1) ans += 2 * v[i]; 
		ans += v[n/2-1];
		ans -= v[n/2];
		for (int i = n/2+1; i < n; i++) ans -= 2 * v[i];
		cout << ans << endl;
		
	}
}