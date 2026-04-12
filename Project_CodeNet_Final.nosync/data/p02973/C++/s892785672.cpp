#include <bits/stdc++.h>
using namespace std;

#define INF (1000000000+1)

int main()
{
	int N;
	cin >> N;
	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	vector<int> dp( N, INF );
	for( int i = N - 1; i >= 0; i-- ) {
		*lower_bound( dp.begin(), dp.end(), A[i], []( int a, int b ) { return a <= b; } ) = A[i];
	}
	int ans = lower_bound( dp.begin(), dp.end(), INF ) - dp.begin();

	cout << ans << endl;
}
