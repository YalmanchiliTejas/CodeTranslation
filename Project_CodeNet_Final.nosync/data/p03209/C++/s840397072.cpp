#include <bits/stdc++.h>
using namespace std;

#define MAX 50

long long N;
long long X;

long long num[MAX + 1][2];

long long dfs( long long n, long long x, long long add )
{
	if( n > 0 && x <= n ) {
		return add;
	}
	else if( num[n][0] - n <= x && x <= num[n][0] ) {
		return num[n][1] + add;
	}
	else if( x <= num[n - 1][0] - (n - 1) + 1 ) {
		return dfs( n - 1, x - 1, add );
	}
	else if( num[n - 1][0] - (n - 1) + 1 <= x && x <= num[n - 1][0] + 1 ) {
		return num[n - 1][1] + add;
	}
	else if( num[n - 1][0] + 1 < x && x <= num[n - 1][0] + 2 ) {
		return num[n - 1][1] + 1 + add;
	}
	return dfs( n - 1, x - ( num[n - 1][0] + 2 ), add + num[n - 1][1] + 1 );
}

int main() {
	cin >> N >> X;

	num[0][0] = 1;
	num[0][1] = 1;
	for( int i = 0; i < 50; i++ ) {
		num[i + 1][0] = num[i][0] + (1LL << (i + 1)) * 2;
		num[i + 1][1] = num[i][1] + (1LL << (i + 1));
	}

	long long ans = dfs( N, X, 0 );

	cout << ans << endl;

	return 0;
}
