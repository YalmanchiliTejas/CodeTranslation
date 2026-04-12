#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void cmpmax(T* reference, T value) {
	*reference = max(*reference, value);
}

template<typename T>
void cmpmin(T* reference, T value) {
	*reference = min(*reference, value);
}

const ll mod = 998244353;

static const ll INF = 1e15;


int main() {
	int n;
	cin >> n;
	vector<ll> vs(n, 0);
	rep(i, n) {
		cin >> vs[i];
	}
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	if (n % 2 == 0) {
		rep(i, n) {
			dp[i][i] = -vs[i];
		}
	}
	else {
		rep(i, n) {
			dp[i][i] = vs[i];
		}
	}
	for (int len = 1; len < n; len++) {
		for (int left = 0; left + len< n; left++) {
			int right = left + len;
			int sign = (n - len - 1) % 2 == 0 ? 1 : -1;
			ll a = dp[left][right - 1] + vs[right] * sign;
			ll b = dp[left+1][right] + vs[left] * sign;
			if (sign > 0) {
				dp[left][right] = max(a, b);
			}
			else{
				dp[left][right] = min(a, b);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
	