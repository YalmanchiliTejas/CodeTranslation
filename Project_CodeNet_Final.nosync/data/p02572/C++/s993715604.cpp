#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define MOD 1000000007

const ll mod = 1e9 + 7;

ll power(ll a, ll b) { //a^b
	ll res = 1;
	a = a % MOD;
	while (b > 0) {
		if (b & 1) {res = (res * a) % MOD; b--;}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vl v(n);
	for (ll i = 0; i < n; i++)
		cin >> v[i];
	vl suf(n);
	suf[n - 1] = v[n - 1];
	for (ll i = n - 2; i >= 0; i--)
		suf[i] = (suf[i + 1] + v[i]) % mod;
	ll ans = 0;
	for (ll i = 0; i < n - 1; i++)
		ans = (ans + (v[i] * suf[i + 1]) % mod) % mod;
	cout << ans << "\n";
}
