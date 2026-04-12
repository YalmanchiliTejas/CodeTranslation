#include <iostream>
#define int long long
using namespace std;

int n, x;
int Pcnt[51];
int Bcnt[51];
int maisu[51];

signed main() {
	int i;
	
	cin >> n >> x;
	
	Pcnt[0] = 1; maisu[0] = 1;
	for (i = 1; i <= n; i++) {
		Pcnt[i] = 2 * Pcnt[i - 1] + 1;
		Bcnt[i] = 2 * Bcnt[i - 1] + 2;
		maisu[i] = Pcnt[i] + Bcnt[i];
	}
	
	int remX = x;
	int ans = 0;
	for (i = n; i >= 0; i--) {
		if (i == 0) { if (remX > 0) { ans++; remX--; } break; }
		remX--; if (remX == 0) { break; } //B
		if (remX <= maisu[i - 1]) { continue; }
		remX -= maisu[i - 1]; ans += Pcnt[i - 1];
		remX--; ans++; if (remX == 0) { break; } //P
		if (remX <= maisu[i - 1]) { continue; }
		remX -= maisu[i - 1]; ans += Pcnt[i - 1];
		remX--; if (remX == 0) { break; } //B
	}
	cout << ans << endl;
	return 0;
}