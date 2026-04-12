#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int n;
vector<ll> arr (50);

ll max(ll a, ll b) {
	if(a > b) {
		return a;
	}
	return b;
}

bool check(ll num) { //a[i]-x*n+(num-x) <= n-1       a[i]+num-n+1 >= (n+1)*x;         (a[i]+num-n+1)/(n+1) <= x
	ll count = 0;
	for(int i = 0; i < n; i++) {
		ll div = arr[i]+num-n+1;
		ll x;
		if(div <= 0) {
			x = 0;
		} else {
			x = div/(n+1);
			if(div%(n+1) != 0) {
				x++;
			}
		}
		count+= x;
	}
	return (num >= count);
}

ll binary(ll from, ll to) {
	if(from >= to) {
		return from;
	}
	ll mid = (from+to)/2;
	if(check(mid)) {
		return binary(from,mid);
	} else {
		return binary(mid+1,to);
	}
}

int main() {
	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum+= arr[i];
	}
	ll ans = binary(max(0,sum-n*(n-1)),600000000000000000);
	for(ll i = max(0,ans-5000); i < ans+5000; i++) {
		if(check(i)) {
			cout << i;
			return 0;
		}
	}
	return 0;
}
