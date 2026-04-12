#include <bits/stdc++.h>
using namespace std;
char s[10];
int main(){
	scanf( "%s", s ); int len = strlen(s);
	for( int i = 0; i <= len - 1; i++ ) if( s[i] == 'A' && s[i+1] == 'C' ){
		printf( "Yes" ); return 0;
	}
	puts("No");
}