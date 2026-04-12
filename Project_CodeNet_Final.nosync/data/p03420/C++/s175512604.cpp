#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, ans;

int main()
{
	cin >> n >> k;
	if(k == 0) {
		cout << n * n;
		return 0;
	}
	for(ll i=k+1;i<=n;i++) {
		for(ll j=0;j<=n;j+=i) {
			ans += max(0ll, min(i-1, n-j) - k + 1);
		}
	}
	cout << ans;
}
