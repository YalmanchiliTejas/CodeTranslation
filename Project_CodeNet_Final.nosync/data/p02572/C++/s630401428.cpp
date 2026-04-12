#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll s=0, c=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		c+=a[i];
	}
	for(int i=0; i+1<n; ++i) {
		c-=a[i];
		s=((((a[i]%M)*(c%M))%M)+(s%M))%M;
	}
	cout << s%M << "\n";
}
