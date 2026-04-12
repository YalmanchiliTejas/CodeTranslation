#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio( false );

	int N;
	cin >> N;

	int result = 0;
	int hmax = 0;

	for( int i = 0; i < N; ++i ) {
		int h;
		cin >> h;

		if( h >= hmax ) {
			hmax = h;
			result += 1;
		}
	}

	cout << result << endl;

	return 0;
}
