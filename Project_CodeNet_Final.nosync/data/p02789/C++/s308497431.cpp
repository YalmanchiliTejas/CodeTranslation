#include <iostream>
using namespace std;

int main ( void )
{
	int N, M;

	cin >> N >> M;

	if ( ( N < 1 ) || ( 100 < N ) ){
		cout << "ERROR!\n";
		return 0;
	}
	if ( ( M < 0 ) || ( N < M ) ){
		cout << "ERROR!\n";
		return 0;
	}

	if ( N == M ){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}