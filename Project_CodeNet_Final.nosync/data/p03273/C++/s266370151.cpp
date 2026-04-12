#include <bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE
#define pb(a) push_back(a)
#define all(a) (a.begin(), a.end())

using ll = long long;

const int E5 = 1e5;

//////////// Solution /////////////////////////////////

void solve() {
	char matr[100][100];
	bool removed[100][100];
	int h,w;
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> matr[i][j];
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			removed[i][j] = false;
		}
	}

	while (1) {
		bool was_any_change = false;

		for (int i = 0; i < h; ++i) {
			bool all_white = true;
			bool comp_removed = true;
			for (int j = 0; j < w; ++j) {
				if (removed[i][j]) {
					continue;
				}
				comp_removed = false;
				if (matr[i][j] == '#') {
					all_white = false;
					break;
				}
			}

			if (!comp_removed && all_white) {
				for (int j = 0; j < w; ++j) {
					removed[i][j] = true;
					was_any_change = true;
				}
			}
		}

		for (int j = 0; j < w; ++j) {
			bool all_white = true;
			bool comp_removed = true;
			for (int i = 0; i < h; ++i) {
				if (removed[i][j]) {
					continue;
				}
				comp_removed = false;
				if (matr[i][j] == '#') {
					all_white = false;
					break;
				}
			}
			if (!comp_removed && all_white) {
				for (int i = 0; i < h; ++i) {
					removed[i][j] = true;
					was_any_change = true;
				}
			}
		}

		if (!was_any_change)
			break;
	}

	for (int i = 0; i < h; ++i) {
		bool comp_removed = true;
		for (int j = 0; j < w; ++j) {
			if (!removed[i][j]) {
				cout << matr[i][j];
				comp_removed = false;
			}
		}
		if (!comp_removed)
			cout << '\n';
	}
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