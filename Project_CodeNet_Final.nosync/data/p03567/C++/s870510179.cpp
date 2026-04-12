#include <bits/stdc++.h>

using namespace std;
int _w;

int n;
char s[10];

int main() {
	_w = scanf( "%s", s );
	n = strlen(s);
	for( int i = 0; i < n-1; ++i )
		if( s[i] == 'A' && s[i+1] == 'C' )
			return puts("Yes"), 0;
	return puts("No"), 0;
}
