#include <iostream>

using namespace std;

int main()
{
	int r,g,b,sum;
	cin >> r;
	cin >> g;
	cin >> b;
	if ((10*g+b)%4 == 0) 
		cout << "YES";
	else
		cout << "NO";
	
	return 0;

}