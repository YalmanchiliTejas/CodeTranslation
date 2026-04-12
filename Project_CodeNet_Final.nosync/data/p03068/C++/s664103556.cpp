#include "bits/stdc++.h"
using namespace std;

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
	}

	void solve() {
		int N, K;
		string S;
		cin >> N >> S >> K;

		for( int i = 0; i < N; ++i ) {
			if( S[i] == S[K-1] ) {
				cout << S[i];
			}
			else {
				cout << '*';
			}
		}

		cout << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
