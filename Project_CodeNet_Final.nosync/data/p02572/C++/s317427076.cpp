#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO; 

	int n;
	cin >> n;
	ll ans = 0;
	vector<ll> v(n), dp(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	dp[0] = v[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = v[i] + dp[i-1];
	}
	
	for (int i = 1; i < n; ++i) {
		ans += ((dp[i-1]%INF) * (v[i]%INF)) % INF;
	}
	cout << ans%INF;
	


}

