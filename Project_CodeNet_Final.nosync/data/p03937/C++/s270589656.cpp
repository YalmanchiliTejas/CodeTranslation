#include <iostream>
using namespace std;
int main()
{
	int h,w;
	int c=0;
	int d=0;
	int a[8][8];
	char b;
	cin >> h >> w;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> b;
			if(b == '#')
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}
	if(a[c][d] == 0)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	while(1)
	{
		if(c < (h-1) && d < (w-1))
		{
			if(a[c+1][d] == 1 && a[c][d+1] == 0)
			{
				c++;
				if(d > 0)
				{
					if(a[c][d-1] == 1)
					{
						cout << "Impossible" << endl;
						return 0;
					}
				}
			}
			else
			{
				if(a[c+1][d] == 0 && a[c][d+1] == 1)
				{
					d++;
					if(c > 0)
					{
						if(a[c-1][d] == 1)
						{
							cout << "Impossible" << endl;
							return 0;
						}
					}
				}
				else
				{
					cout << "Impossible" << endl;
					return 0;
				}
			}
		}
		else
		{
			if(c == (h-1) && d < (w-1))
			{
				if(a[c][d+1] == 1)
				{
					d++;
					if(c > 0)
					{
						if(a[c-1][d] == 1)
						{
							cout << "Impossible" << endl;
							return 0;
						}
					}
				}
				else
				{
					cout << "Impossible" << endl;
					return 0;
				}
			}
			else
			{
				if(c < (h-1) && d == (w-1))
				{
					if(a[c+1][d] == 1)
					{
						c++;
						if(d > 0)
						{
							if(a[c][d-1] == 1)
							{
								cout << "Impossible" << endl;
								return 0;
							}
						}
					}
					else
					{
						cout << "Impossible" << endl;
						return 0;
					}
				}
				else
				{
					cout << "Possible" << endl;
					return 0;
				}
			}
		}
	}
}