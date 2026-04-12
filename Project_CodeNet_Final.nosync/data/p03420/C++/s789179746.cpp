#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	int64_t sum = 0;
	cin >> N >> K;

	for ( int i = K + 1; i <= N; i++ ) {
		int p = N / i, r = N % i;
		sum += p * max(0, i - K) + max(0, r - K + 1);
	}
	if ( K == 0 ) sum -= N;
	cout << sum << endl;

	return ( 0 );
}
