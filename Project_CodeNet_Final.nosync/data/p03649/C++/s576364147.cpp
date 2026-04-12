#include <iostream>
using namespace std;
typedef long long ll;
ll n, mx, mi, ans, a[55];
int main() {
	ll i, t;
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>a[i];
		if(a[i]>mx) mx=a[i], mi=i;
	}
	while(mx>=n) {
		t = mx / n;
		ans += t;
		for(i=0; i<n; i++) a[i] += t;
		a[mi] = mx%n;
		mx = -1;
		for(i=0; i<n; i++) if(a[i]>mx) mx=a[i], mi=i;
	}
	cout<<ans;
	return 0;
}