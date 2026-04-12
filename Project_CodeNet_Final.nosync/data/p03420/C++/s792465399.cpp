#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,k;
	cin >> n >> k;
	if(k==0)
	{
		cout<<n*n<<endl;
		return 0;
	}
	ll ans = 0;
	for(ll i = 1;i<=n;i++)
	{
		if(i-k<=0)continue;
		ll  asd = n/i * (i-k);
		ans += asd;
		ll  qwe = max(n%i-k+1,0LL);
		ans += qwe;
	}
	cout<<ans<<endl;
	return 0;
}