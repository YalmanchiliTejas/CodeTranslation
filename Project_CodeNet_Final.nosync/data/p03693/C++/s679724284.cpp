#include <iostream>
using namespace std;

int main()
{
	int r, g, b, o;
	cin >> r >> g >> b;
	o = 100*r + 10*g + b;
	if (o % 4 == 0)
	cout << "YES";
	else
	cout << "NO";	
}