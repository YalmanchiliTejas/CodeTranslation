#include <iostream>
using namespace std;

long long ans = 0;
long long x;

long long patties[60];
long long total[60];
long long buns[60];

void solve(int n) {
	if( x == 0) return;
	
	if (n == 0) {
		ans++;
		x--;
	} else {
		
		if (x >= total[n]) {
			x -= total[n];
			ans += patties[n];
			return;
		}
		
		x--; // me como un pan
		
		if (x > 0) solve(n-1);
		
		if (x > 0) {
			x--;
			ans++;
		}
		
		if (x > 0) solve(n-1);
		
		if (x > 0) x--; // me como el otro pan
	}
}
int main() {
	// your code goes here
	int n; cin >> n >> x;
	
	total[0] = 1;
	patties[0] = 1;
	
	for(int i = 1; i <= n; i++) {
		buns[i] = 2*buns[i-1] + 2;
		patties[i] = 2*patties[i-1] + 1;
		total[i] = buns[i] + patties[i];
	}

	solve(n);
	cout << ans << endl;
	return 0;
}