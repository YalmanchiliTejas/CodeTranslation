#include <bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE
#define ll long long
#define PI 3.14159265359
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define pb(a) push_back(a)

//////////// Solution /////////////////////////////////

int h[20];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	int ans = 1;
	int mx = h[0];
	for (int i = 1; i < n; ++i) {
		if (mx <= h[i]) {
			++ans;
			mx = h[i];
		}
	}

	cout << ans << '\n';
}

	/////////// End Solution ///////////////////////////////////////

	//////// Initialization ////////////////////////////////////

int main() {

		#ifndef ONLINE_JUDGE
	FILE *FIN = freopen("/home/danil/prog/input.txt", "r", stdin);
	clock_t time_start = clock();
		#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

		#ifndef ONLINE_JUDGE
	fclose(FIN);
	cerr << "\x1b[031m\n-----------------\nTime=" << (ll)((double)(clock()-time_start) / CLOCKS_PER_SEC * 1000) << "ms\n\x1b[0m";
		#endif

	return 0;
}

	//////// End Initialization ///////////////////////////////////////