#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e5+5, M = 1e9+7;
ll a[mxN];

ll mul(ll a, ll b) {
	return (a%M * b%M)%M;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	ll sum = a[n-1];
	for(int i = n-2; i >= 0; i--) {
		ans = (ans + mul(sum, a[i]))%M;
		sum = (sum + a[i])%M;
	}
	cout << ans << '\n';
}
