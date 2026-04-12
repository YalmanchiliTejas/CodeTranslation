#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
using namespace std;

void printV(vll v){
	cout << "size (" << v.size() << "): ";
	for(ll i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}

void printM(vector<vll> v){
	cout << "size (" << v.size() << "," << v[0].size() << "): ";
	for(ll i = 0; i < v.size(); i++){
		for(ll j = 0; j < v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

ll powermod(ll x, ll y){
	ll res = 1;
	x = x % mod;
	while (y > 0)
	{
		if (y & 1){
			res = (res * x) % mod;
		}
		y = y >> 1;
		x = (x * x) % mod;
	}
	res %= mod;
	return res;
}

ll factmod(ll n)
{
	ll res = 1;
	while (n > 1)
	{
		res = (res * ((n / mod) % 2 ?  mod - 1 : 1)) % mod;
		for (ll i = 2; i <= n % mod; ++i){
			res = (res * i) % mod;
		}
		n /= mod;
	}
	res %= mod;
	return res;
}

void solve(){
	ll temp;
	cin >> temp;
	if(temp >= 30) cout << "Yes\n";
	else cout << "No\n";
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;
//	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}