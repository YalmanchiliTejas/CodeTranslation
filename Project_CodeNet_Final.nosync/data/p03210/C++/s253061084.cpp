#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std ;
typedef long long ll ;
# define rep (i , n ) for ( int i =0; i < n ; i++)

int main()
{
	cin.tie(NULL);

	int X;
	cin >> X;

	if ((X == 3) || (X == 5) || (X == 7) )
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}