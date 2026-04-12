#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll arr[n+1];
	for(int i = 1; i <= n;++i){
		cin >> arr[i];
	}
	ll suf[n+1];
	suf[n] = arr[n];
	for(int i = n-1; i > 0;--i){
		suf[i] = suf[i+1] + arr[i];
	}
	ll ans = 0;
	for(int i = 1; i < n;++i){
		ans = (ans + ((arr[i]%MOD) * (suf[i+1]%MOD))%MOD)%MOD;
	}
	cout << ans << "\n";
}
