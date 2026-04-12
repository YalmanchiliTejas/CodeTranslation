#include <iostream>
using namespace std;
 
int main()
{
	int X;
	cin >> X;
 
	if (-40 <= X && X <= 29)
	{
		cout << "No";
	}
	else if (X >= 30 && X <= 40)
	{
		cout << "Yes";
	}
}