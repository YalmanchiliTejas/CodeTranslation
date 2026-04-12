#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	a *= 100, b *= 10;
	if((a + b + c) % 4) printf( "NO\n" );
	else printf( "YES\n" );
	return 0;
} 