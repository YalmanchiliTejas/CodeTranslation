#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define MOD 1000000007

signed main(){
	int n;
	cin >> n;
	int a[200010];
	for(int i = 0;i < n;i++) cin >> a[i];

	int ans = 0;
	int tmp = 0;
	for(int i = 0;i < n;i++){
		ans += (tmp * a[i]) % MOD;
		ans %= MOD;
		tmp = (tmp + a[i]) % MOD;
	}

	cout << ans << endl;

	return 0;
}
