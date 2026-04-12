#include<bits/stdc++.h>
using namespace std;

#define OM ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pi 3.14159265358979323846

typedef long long ll;

/*LETS BEGIN WITH THE NAME OF MAHADEV*/


/*ll mul(ll a, ll b, ll m){
	ll res = 0;
	a = a % m;
	while(b){
		if(b & 1)
			res = (res + a) % m;
		a = (a + a) % m;
		b >>= 1; 
	}
	return res;
}
*/
int main()
{
	OM;
	int n;
	cin >> n;
	const ll m = 1e9 + 7;
	vector<ll> v(n), pref(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
		pref[i] = i ? (pref[i - 1] + v[i]) % m : v[i] % m;
	}
	ll answer = 0;
	for(int i = 0; i < n; ++i){
		answer = (answer + (v[i] * (pref[n - 1] - pref[i] + m) % m) % m) % m;
	}
	cout << answer << endl;
	return 0;
}