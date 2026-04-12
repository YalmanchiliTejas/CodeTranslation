#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;

template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, T b) { if(b < a) a = b; }

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	for(int n; cin >> n, n;) {
		int sum = 0, mx = 0, mn = INT_MAX;
		for(int i = 0; i < n; ++i) {
			int score;
			cin >> score;
			sum += score;
			chmax(mx, score);
			chmin(mn, score);
		}

		cout << (sum - mx - mn) / (n - 2) << endl;
	}

	return EXIT_SUCCESS;
}