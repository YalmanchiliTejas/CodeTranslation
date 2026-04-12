#include <bits/stdc++.h>
using namespace std;

#define MAX 20

int N;
int H[MAX];

int main() {
	cin >> N;
	for( int i = 0; i < N; i++ ) {
		cin >> H[i];
	}
	int ans = 1;
	int ma = H[0];
	for( int i = 1; i < N; i++ ) {
		if( H[i] >= ma ) {
			ma = H[i];
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
