
#include <bits/stdc++.h>
using namespace std;

char S[ 20 ];


int main()
{
int i;
int N;
int K;
char C;
char cChk;

	ios::sync_with_stdio( false );
	cin.tie( 0 );

	cin >> N;
	cin >> S;
	cin >> K;

	cChk = S[ K - 1 ];
	i = 0;
	while( C = S[ i ] )
	{
		if( C != cChk ) S[ i ] = '*';

		i++;
	}

	cout << S << endl;

	return 0;
}
