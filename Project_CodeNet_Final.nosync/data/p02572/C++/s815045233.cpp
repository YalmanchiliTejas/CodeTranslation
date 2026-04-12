/*
 *  Created on: 29 / 8 / 2020
 *  Author:     Eslam Waheed
 */

#define _CRT_SECURE_NO_WARNINGS
//#define __USE_MINGW_ANSI_STDIO

#include <bits/stdc++.h>
//#include <bits/BIGINT.h>
//#include <bits/Int128.h>
using namespace std;

#define Eslam__Waheed ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

#define ll   long long
#define ull  unsigned ll
#define ld   long double

#define all(c)   c.begin(), c.end()
#define rall(c)  c.rbegin(), c.rend()
#define stp(n)   cout << fixed << setprecision(n);
#define iq(v)    v.resize(unique(v.begin(),v.end())-v.begin())
#define sz(s)    s.size()
#define endl     '\n'

//ll gcd(ll a, ll b) { return !b ? abs(a) : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return abs(a / gcd(a, b)) * b; }

//const ld PI = acos(-1);
const ll mod = 1e9 + 7;
//const ld EPS = 1e-8;
/*
 you can ^_^ (•‿•)

( إن الله وملائكته يصلون على النبي يا أيها الذين آمنوا صلوا عليه وسلموا تسليما )
*/
int main()
{
	//stp(0)
	Eslam__Waheed;
	ll n; cin >> n;
	vector<ll>v(n);
	for (auto& it : v)
	{
		cin >> it;
	}
	vector<ll>temp(v);
	for (int i = n - 1; i > 0; i--)
	{
		v[i - 1] += v[i];
	}
	ll ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ans = ((ans % mod) + ((v[i + 1] % mod) * (temp[i] % mod)) % mod) % mod;
	}
	cout << ans;
}