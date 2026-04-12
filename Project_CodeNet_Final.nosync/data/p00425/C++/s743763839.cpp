#include <iostream>
using namespace std;

int main()
{
	int n, w;	//top, south, east
	char o[6];

	while (cin >> n && n)
	{
		int r = 1, t = 1, s = 2, e = 3;
		for (; n > 0; --n)
		{
			cin >> o;
			switch (o[0])
			{
			case 'N':
				w = t;
				t = s;
				s = 7-w;
				break;
			case 'E':
				w = t;
				t = 7-e;
				e = w;
				break;
			case 'W':
				w = t;
				t = e;
				e = 7-w;
				break;
			case 'S':
				w = t;
				t = 7-s;
				s = w;
				break;
			case 'R':
				w = s;
				s = e;
				e = 7-w;
				break;
			case 'L':
				w = s;
				s = 7-e;
				e = w;
				break;
			}
			r += t;
		}
		cout << r << endl;
	}

	return 0;
}