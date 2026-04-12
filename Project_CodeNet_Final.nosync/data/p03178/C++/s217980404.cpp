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

const ll mod = 1000000007;

static const ll INF = 1e15;


int main() {
	string k;
	int d;
	cin >> k;
	cin >> d;
	int n = k.size();
	vector<int> digits(n, 0);
	rep(i, n) {
		digits[i] = k[i] - '0';
	}
	vector<vector<ll>> dp[2];
	dp[0].assign(n, vector<ll>(d, 0));
	dp[1].assign(n, vector<ll>(d, 0));
	for (int i = 0; i < digits[0]; i++) {
		dp[0][0][i % d] ++;
	}
	dp[1][0][digits[0] % d] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < d; j++) {
			for (int a = 0; a < 10; a++) {
				int r = j + a;
				r %= d;
				dp[0][i][r] += dp[0][i - 1][j];
				dp[0][i][r] %= mod;
			}
		}
		for (int j = 0; j < d; j++) {
			if (dp[1][i-1][j]) {
				for (int a = 0; a < digits[i]; a++) {
					int r = j + a;
					r %= d;
					dp[0][i][r] += dp[1][i - 1][j];
					dp[0][i][r] %= mod;
				}
				{
					int r = j + digits[i];
					r %= d;
					dp[1][i][r] += dp[1][i - 1][j];
					dp[1][i][r] %= mod;
				}
			}
		}
	}
	ll sum = 0;
	sum += dp[0][n - 1][0];
	sum += dp[1][n - 1][0];
	sum %= mod;
	sum += mod - 1;
	sum %= mod;
	cout << sum << endl;
	return 0;
}
	
