#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

const ll N = 2e5 + 10;
const ll p = 1e9 + 7;

ll n;
ll a[N];
ll res = 0;
ll q[N];

int main() {
	cin >> n;
	
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= p;
		q[i] = (q[i - 1] + a[i]) % p;
	}
	
	for (ll i = 1; i <= n; i++) {
		res = (res % p) + ((a[i] * ((q[n] - q[i] + p)) % p) % p);
//		cout << i << ":" << (q[n] - q[i]) << endl;
	}
	
	cout << res << endl;
	
	return 0;
}