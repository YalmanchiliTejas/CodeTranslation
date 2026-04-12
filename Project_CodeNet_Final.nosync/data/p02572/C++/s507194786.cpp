#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const int mod = 1e9+7;
ll arr[N],pref[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1 ; i <=n ; i++)
		pref[i] = (pref[i-1]%mod+arr[i]%mod)%mod;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans%mod + (arr[i]%mod*(pref[n]-pref[i]+mod)%mod)%mod)%mod;
	cout << ans;
	return 0;
}
