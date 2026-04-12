#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mod 1000000007

int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll ans = 0, n, i, j;
	cin >> n;

	ll a[n], pre_sum[n + 1] = {};

	rep(i, 0, n) {
		cin >> a[i];
		if (i == 0)
			pre_sum[i] = a[i];
		else
			pre_sum[i] = pre_sum[i - 1] + a[i];
	}
	rep(i, 0, n)
	{
		ll tmp = (pre_sum[n - 1] - pre_sum[i])%mod * a[i]%mod;
		tmp %= mod;
		ans += tmp;
		ans %= mod;
	}
	cout << ans << endl;



	return 0;
}