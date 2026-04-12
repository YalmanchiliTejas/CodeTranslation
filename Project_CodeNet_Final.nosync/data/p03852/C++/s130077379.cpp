
#include <bits/stdc++.h>
using namespace std;

int main( int argc, char *argv[] )
{
char c;

	ios::sync_with_stdio( false );
	cin.tie( 0 );

	cin >> c;
	if( c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' )
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;

	return 0;
}


