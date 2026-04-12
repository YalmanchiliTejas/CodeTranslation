#include <iostream>
using namespace std;
int main()
{
	int a, b, i, m;
	char c;
	while (1)
	{
		m = 0;
		for (i = 0; i < 5; i++)
		{
			cin >> a >> b;
			if (a == 0 && b == 0) return 0;
			if (a+b > m)
			{
				m = a+b;
				c = 'A' + i;
			}
		}
		cout << c << " " << m << endl;
	}
}