#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long int ll;

int main(){
	ll sum = 0;
	ll ans = 0;
	ll mod = 1e9 + 7;
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		sum += v[i];
	for (int i = 0; i < n - 1; i++){
		sum -= v[i];
		ll tmp = (sum % mod) * v[i];
		ans = (ans + tmp) % mod;
	}
	cout << ans << '\n';
	return 0;
}
