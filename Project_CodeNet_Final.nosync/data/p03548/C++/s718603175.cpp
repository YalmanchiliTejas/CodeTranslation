#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a, b, c;
	int x = 1;
	int y = 1;
	cin >> a >> b >> c;

	while (1)
	{		
		if ((b + c)* x + c > a)
		{
			x--;
			break;
		}
		x++;
	}

	cout << x;

}	
