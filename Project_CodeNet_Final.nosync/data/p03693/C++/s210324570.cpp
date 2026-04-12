
#include <bits/stdc++.h>
using namespace std;

int main( int argc, char *argv[] )
{
int r;
int g;
int b;

	ios::sync_with_stdio( false );
	cin.tie( 0 );

	cin >> r;
	cin >> g;
	cin >> b;
	if( ( g * 10 + b ) % 4 == 0 )
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}


