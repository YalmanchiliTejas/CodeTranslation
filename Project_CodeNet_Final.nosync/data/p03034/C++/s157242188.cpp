#include <iostream>
#include <algorithm>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;
 
int n;
int s[200000];
 
signed main() {
	int i, j;
	
	cin >> n;
	rep(i, n) cin >> s[i];
	
	int ans = 0;
	for (i = 1; i < n; i++) {
		int score = 0;
		for (j = 0; j < n - i; j += i) {
			score += s[j] + s[n - 1 - j];
			if ((n - 1) % i == 0 && j >= n - 1 - j) {
				break;
			}
			ans = max(ans, score);
		}
	}
	cout << ans << endl;
	return 0;
}