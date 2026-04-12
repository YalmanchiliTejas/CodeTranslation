#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	int64_t sum = 0;
	cin >> N >> K;

	for ( int i = K + 1; i <= N; i++ ) {
		int a = K, b = i - 1;

		while ( a <= N ) {
			sum += min(b, N) - max(a, 1) + 1;
			a += i, b += i;
		}

	}

	cout << sum << endl;

	return ( 0 );
}
