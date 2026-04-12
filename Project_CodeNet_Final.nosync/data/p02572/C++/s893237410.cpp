#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll a[200200], s, mod = 1e9 + 7, ans;

ll pw(ll n, ll k){
    if(!k) return 1;
    ll re = pw(n, k/2) % mod;
    return re * re % mod * (k % 2 ? n : 1) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i], s = (s + a[i]) % mod;

	ans = s * s % mod;
	for(int i=1;i<=n;i++) ans = (ans - a[i] * a[i] + mod * mod) % mod;

	cout << ans * pw(2, mod - 2) % mod;
}