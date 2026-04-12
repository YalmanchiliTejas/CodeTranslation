#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
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
	ll n, x, m;
	cin >> n >> x >> m;
	vector <pair<ll, ll> > vis(m, {0, 0});
	vis[x].ff = x;
	vis[x].ss = 1;
	ll sum = x;
	ll c = 2;
	while (true) {
		if (c > n)
			break;
		ll cur = (x * x) % m;
		if (vis[cur].ss == 0) {
			vis[cur].ss = c;
			c++;
			sum += cur;
			vis[cur].ff = sum;
			x = cur;
			continue;
		}
		ll cyc = c - vis[cur].ss;
		ll csum = sum - vis[cur].ff + cur;
		ll lef = n - c + 1;
		sum += (lef / cyc) * csum;
		lef = lef - (lef / cyc) * cyc;
		//cout << lef << "\n";
		while (lef--) {
			cur = (x * x) % m;
			sum += cur;
			x = cur;
		}
		break;
	}
	cout << sum << "\n";
}
