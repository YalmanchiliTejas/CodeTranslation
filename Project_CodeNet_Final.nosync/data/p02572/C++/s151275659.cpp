#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 500005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long

#define mod  1000000007



int main()
{
	FAST;
	int n;
	cin >> n;
	ll a[n + 6];
	ll x = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		x += a[i];
	}
	
	ll ans = 0;
	for(int i = 0; i < n-1; i ++){
		x -= a[i];
		ans += (x%mod)*a[i];
		ans %= mod;
		
	}
	cout << ans;
	return 0;
}