#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;




int main()
{
	int m = 1000000007;
	int n;
	cin >> n;
	vector<long long> v(n);
	vector<long long> pref(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == 0) pref[0] = v[0]%m;
		else {
			pref[i] = ((pref[i - 1] % m) + (v[i] % m)) % m;
			pref[i] % m;
		}
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ans += ((v[i] % m) * (pref[i - 1] % m)) % m;
		ans %= m;
	}
	cout << ans;
	
	
	

}

