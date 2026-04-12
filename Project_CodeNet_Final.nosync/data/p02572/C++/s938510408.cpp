#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

#define MOD 1000000007

typedef long long int ll;

int main() {

	IOS

	int n;
	cin >> n;
	
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll sum = 0;

	for (int i = 0; i < n; i++)
		sum = (sum + a[i]) % MOD;

	ll res = 0;

	for (int i = 0; i < n; i++) {
		sum = (sum - a[i] + MOD) % MOD;
		res = (res + (a[i] * sum) % MOD) % MOD;
	}

	cout << res;

	return 0;
}