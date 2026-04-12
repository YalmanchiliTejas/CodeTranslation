#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 2e5 + 5;
const int oo = 1e9 + 5;
const LL ooll = 1e18 + 5;
 
// clock_t start = clock();


void solve() {
	int x;
	cin >> x;
	cout << (x >= 30 ? "Yes" : "No") << '\n';
}
 
int main() {
	FASTIO;
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	// cout << fixed << setprecision(10);
	// cout << (clock() - start) / ((long double)CLOCKS_PER_SEC) << '\n';
	return 0;
} 