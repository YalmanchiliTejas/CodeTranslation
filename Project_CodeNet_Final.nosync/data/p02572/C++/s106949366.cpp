#include <iostream>
#include <cstdio>

using namespace std;

#define S_MOD 1000000007

void main_body( void )
{
	int N;
	long long A[ 200000 ];
	long long total = 0;
	long long ans = 0;

	cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		cin >> A[ i ];

		total += A[ i ];
	}

	for ( int i = 0; i < ( N - 1 ); i++ )
	{
		total -= A[ i ];

		ans += (total % S_MOD) * A[ i ];
		ans %= S_MOD;
	}

	cout << ans << endl;

	return;
}

int main( int argc, char *argv[] )
{
	int c;

	if ( argc > 1 )
	{
		c = atoi( argv[ 1 ] );
	}
	else
	{
		c = 1;
	}

	for ( int i = 0; i < c; i++ )
	{
		main_body();
	}

	return 0;
}
