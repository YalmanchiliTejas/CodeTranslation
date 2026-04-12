#include<iostream>
using namespace std;


int main()
{
	double X, Y, Z;
	cin >> X >> Y >> Z;
	int c = 0;
	int t = X;
	while (true)
	{
		if (c == 0)
		{
			if (t >= Y + Z * 2)
			{
				c++;
				t -= Y + Z * 2;
			}
			else break;
		}
		else
		{
			if (t >= Y + Z)
			{
				c++;
				t -= Y + Z;
			}
			else break;
		}
	}
	cout << c << endl;
	return 0;
}