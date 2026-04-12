#include <bits/stdc++.h>
using namespace std;
char s[100000];
bool judge = false;
int main( ) {
	scanf( "%s", s );
	int len = strlen( s );
	for( register int i = 0; i < len - 1; i++ )
		if( s[i] == 'A' && s[ i + 1 ] == 'C' ) 
			{ judge = true; break; }
	if( judge ) puts( "Yes" );
	else        puts( "No"  );
} 