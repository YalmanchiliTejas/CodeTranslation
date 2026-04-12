#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	ll answer = 0;
	while(true){
		sort(a.begin(), a.end(), greater<ll>());
		int m = 0;
		for(; m < n && a[m] >= a[0] - (n - 1); ++m);
		if(m == n || a[0] < 2 * n){ break; }
		const ll s = n - m + 1;
		const ll k = (a[0] - max<ll>(n, a[m])) / s;
		for(int i = 0; i < m; ++i){ a[i] -= k * s; }
		for(int i = m; i < n; ++i){ a[i] += k * m; }
		answer += k * m;
	}
	sort(a.begin(), a.end(), greater<ll>());
	if(a[0] >= 2 * n){
		const ll k = max(0ll, a[0] - (2 * n));
		for(int i = 0; i < n; ++i){ a[i] -= k; }
		answer += k * n;
	}
	while(a[0] >= n){
		a[0] -= n;
		for(int i = 1; i < n; ++i){ ++a[i]; }
		++answer;
		sort(a.begin(), a.end(), greater<ll>());
	}
	cout << answer << endl;
	return 0;
}

