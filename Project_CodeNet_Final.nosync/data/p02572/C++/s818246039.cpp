#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	const ll MOD = 1e9 + 7;
	int n; cin >> n;
	vector<int>a(n), cum(n+1);
	ll tot = 0, sq = 0;
	for(int i=0;i <n; i++){
		cin >> a[i];
		cum[i+1] = a[i] + cum[i];
		cum[i+1] %= MOD;
	}
	ll ret = 0;
	for(int i=0; i<n-1; i++){
		ll sum = (cum[n]-cum[i+1] + MOD) % MOD;
		ret += (a[i] * sum) % MOD;
		ret %= MOD;
	}
	cout << ret << endl;
	return 0;
}