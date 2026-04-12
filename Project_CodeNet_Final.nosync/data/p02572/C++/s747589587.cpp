#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
ll a[N];

int main()
{
    ll n,sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
		sum %= mod;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		sum = (sum - a[i] + mod) % mod;
		ans = ans + sum * a[i] % mod;
		ans %= mod;
	}
	cout << ans << endl;
}