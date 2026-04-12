#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, ans, a[200005];
int main() {
	ll i;
	cin >> n;
	for(i=0; i<n; i++) scanf("%lld", &a[i]);
	sort(a, a+n);
	m = n/2;
	for(i=0; i<m-1; i++) ans += (a[n-1-i] - a[i]) * 2;
	if(n%2) ans += max(2*a[m+1]-a[m]-a[m-1], a[m+1]+a[m]-2*a[m-1]);
	else ans += a[m] - a[m-1];
	cout << ans;
	return 0;
}