#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto &i:a)cin >> i;
	ll sum = 0;
	ll ans = 0;
	for(int i = n-1;i>0;i--)
	{
		sum += a[i];
		sum %= MOD;
		ans += sum*a[i-1]%MOD;
		ans %=MOD;
	}
	cout<<ans<<endl;
}

