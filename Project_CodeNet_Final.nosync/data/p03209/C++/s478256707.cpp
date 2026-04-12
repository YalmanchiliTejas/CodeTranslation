#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll pattyCount(ll n, ll x) {
	if (n==0) {
		if (x>0) return 1;
		return 0;
	}

	ll l=1, r=1, m;
	for (int i=0; i<n; i++) r = r*2 + 3;
	m=(l+r)/2;
	
	if (x>m) {
		ll add=1;
		for (int i=0; i<n-1; i++) add = add*2 + 1;
		return add+1 + pattyCount(n-1, x-m);
	}
	else if (x<m)
		return pattyCount(n-1,x-1);
	else {
		ll add=1;
		for (int i=0; i<n-1; i++) add = add*2 + 1;
		return add+1;
	}

}
int main() {
	ll n, x; cin>>n>>x;
	cout << pattyCount(n,x) << endl;
	return 0;
}
