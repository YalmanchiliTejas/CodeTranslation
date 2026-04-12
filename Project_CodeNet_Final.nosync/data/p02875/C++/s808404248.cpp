#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll mod = 998244353;
 
ll F[10101010], FI[10101010];
ll n, ans;
 
ll inv(ll x) { return x > 1? mod / x * (mod - inv(mod % x)) % mod : 1; }
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll i, t;
	
	cin >> n;
	
	for(i = 1, F[0] = 1; i <= n; i ++){
		F[i] = F[i - 1] * i % mod;
    }
	
	FI[n] = inv(F[n]);
	
	for(i = n, ans = 1; i; i --){
		FI[i - 1] = FI[i] * i % mod;
		ans = ans * 3 % mod;
    }
	
	for(i = n, t = 2 * F[n] % mod; i + i > n; i --){
		ans = (ans - t * FI[n - i] % mod * FI[i]) % mod;
		t = t * 2 % mod;
    }
	
	cout << (ans + mod) % mod << "\n";
	
	return 0;
}