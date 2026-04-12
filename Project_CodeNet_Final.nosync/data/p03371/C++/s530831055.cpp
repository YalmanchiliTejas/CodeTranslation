#include <bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE
#define pb(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define FOR(x,to) for(x=0;x<(to);x++)

using ll = long long;

const int E5 = 1e5;

//////////// Solution /////////////////////////////////

void solve() {
	ll A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	ll ans = 0;
	if (A+B >= 2*C) {
		ans = min(X,Y) * 2*C;
	} else {
		ans = (A+B) * min(X,Y);
	}

	if (X <= Y) {
		if (B >= 2*C) {
			ans += (Y-X) * 2*C;
		} else {
			ans += (Y-X) * B;
		}
	} else {
		if (A >= 2*C) {
			ans += (X-Y) * 2*C;
		} else {
			ans += (X-Y) * A;
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