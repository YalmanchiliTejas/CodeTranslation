#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
	ll n ,k;
	cin >> n >> k;
	ll ans = 0;
	if(k==0)
	{
		cout<<n*n<<endl;
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		int hoge = n - n%i;
		hoge/=i;
		ans += max(0LL,hoge*(i-k));
		
		ans += max(0LL,n%i-k+1);
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}