#include<bits/stdc++.h>
using namespace std;


#define rep(i, n) for(int i = 0; i < (n); i++)


void solve() {
	int n; cin >> n;
	int h[20]; rep(i, n) cin >> h[i];
	int Mh = 0;
	int ans = 0;
	rep(i, n) {
		if (h[i] >= Mh) ans++;
		Mh = max(Mh, h[i]);
	}
	cout << ans << endl;
}

int main() {


	solve();


	return 0;
}