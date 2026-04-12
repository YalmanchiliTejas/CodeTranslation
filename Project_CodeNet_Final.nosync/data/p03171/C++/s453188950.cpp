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
void cmpmax(T& reference, T value) {
	reference = max(reference, value);
}

template<typename T>
void cmpmin(T& reference, T value) {
	reference = min(reference, value);
}

const ll mod = 1000000007;

static const ll INF = 1e15;

int main() {
	int n;
	cin >> n;
	vector<ll> as(n);
	rep(i, n) cin >> as[i];

	//dp[i][j]...iからjまでのデータに対するX-Yの値
	//dp[i][j]
	//奇数の番の場合...max(dp[i+1][j] + as[i], dp[i][j-1] + as[j])
	//偶数の番の場合...min(dp[i+1][j] - as[i], dp[i][j-1] - as[j])

	vector<vector<ll>> dp(n, vector<ll>(n, INF));
	ll sign = n % 2 ? 1 : -1;
	rep(i, n) {
		dp[i][i] = sign * as[i];
	}
	for (int length = 2; length <= n; length++) {
		for (int left = 0; left <= n - length; left++) {
			int right = left + length - 1;
			bool turn = (n - (right + 1 - left)) % 2;
			if (!turn) {
				ll c1 = dp[left + 1][right] + as[left];
				ll c2 = dp[left][right-1] + as[right];
				dp[left][right] = max(c1, c2);
			}
			else {
				ll c1 = dp[left + 1][right] - as[left];
				ll c2 = dp[left][right - 1] - as[right];
				dp[left][right] = min(c1, c2);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
	
