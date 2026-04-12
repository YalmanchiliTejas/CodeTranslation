#include <iostream>

using namespace std ;
/*
ifstream cin ("input") ;
ofstream cout ("output") ;*/

int main(int argc, char const *argv[])
{
	int a, b, c ;
	cin >> a >> b >> c ;
	if ((b * 10 + c) % 4 == 0) cout << "YES\n" ;
	else cout << "NO\n" ;
	return 0;
}