#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using graph = vector<vector<int>>;

const ll mod = 1000000007;
const int INF = 1001001001;

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> a(n);
	vector<ll> sum(n + 1);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		sum[i + 1] = sum[i] + a[i];
	}
	ll ans = 0;
	for(int i = 0; i < n - 1; i++){
		//cout << a[i] << " " << sum[n] - sum[i + 1] << endl;
		ans += a[i] * ((sum[n] - sum[i + 1]) % mod);
		ans = ans % mod;
	}
	cout << ans << endl;
} 