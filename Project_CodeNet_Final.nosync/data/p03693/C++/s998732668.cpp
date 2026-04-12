#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;

int main() {
	ll r, g, b, ans;
	ans = 0;
	cin >> r >> g >> b;
	ans = r*100 + g*10 + b;
	
	if (ans % 4 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
