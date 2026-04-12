#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i<n; i++)
int main()
{
	ll mod = 1000000007;
	ll ans = 0;
	ll N,inp,sum,zizyo;
	sum = 0;
	cin >> N;
	rep(i,N){
		cin >> inp;
		ans = (ans + sum*inp)%mod;
		sum = (sum + inp)%mod;
	}

	cout << ans;
	cin >> N;
	
	return 0;	
}
