#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;
const int MOD = 1e9+7;

int v[MAX];
int n;
int suff[MAX];

void solve() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> v[i];
	suff[n-1] = v[n-1];
	for(int i=n-2; i>=0; i--) suff[i] = (v[i] + suff[i+1]) % MOD;
	int ans=0;
	for(int i=0; i<n-1; i++) ans = (ans + v[i]*suff[i+1]%MOD) % MOD;
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

