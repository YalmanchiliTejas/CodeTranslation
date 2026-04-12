#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	string S;
	cin >> S;

	string ans = "No";
	for( int i = 0; i < S.size()-1; ++i ) {
		if( S[i] == 'A' && S[i+1] == 'C' ) {
			ans = "Yes";
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
