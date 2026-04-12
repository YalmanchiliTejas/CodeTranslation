#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;
template< typename T >
T mod_pow(T x, T n, const T &p) {
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
}

const ll MOD = 1e9+7;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0;i<n;i++)cin >> a[i];
	ll xx = 0;
	for(int i = 0;i<n;i++)
	{
		(xx += a[i])%=MOD;
	}
	ll ans =0 ;
	for(int i = 0;i<n;i++)
	{
		xx += (MOD-a[i]);
		xx %=MOD;
		ans += xx*a[i]%MOD;
		ans %= MOD;
		
		
	}
	cout<<ans<<endl;
}
