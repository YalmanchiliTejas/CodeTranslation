#include <iostream>
#include <string>
using namespace std;
int main()
{
	while (1)
	{
		int a = 0;
		int aw = 1;
		int c[6] = { 1, 2, 3, 4, 5, 6 };
		cin >> a;
		if (a == 0)
		{
			break;
		}
		string s[10000];
		for (int i = 0; i < a; i++)
		{
			cin >> s[i];
		}
		for (int i = 0; i < a; i++)
		{
			int d[6];
			for (int j = 0; j < 6; j++)
			{
				d[j] = c[j];
			}
			if (s[i] == "North")
			{
				c[0] = d[1];
				c[2] = d[2];
				c[3] = d[3];
				c[1] = d[5];
				c[5] = d[4];
				c[4] = d[0];
				aw += c[0];
			}
			if (s[i] == "East")
			{
				c[0] = d[3];
				c[1] = d[1];
				c[4] = d[4];
				c[2] = d[0];
				c[5] = d[2];
				c[3] = d[5];
				aw += c[0];
			}
			if (s[i] == "West")
			{
				c[0] = d[2];
				c[1] = d[1];
				c[4] = d[4];
				c[2] = d[5];
				c[5] = d[3];
				c[3] = d[0];
				aw += c[0];
			}
			if (s[i] == "South")
			{
				c[0] = d[4];
				c[2] = d[2];
				c[3] = d[3];
				c[1] = d[0];
				c[5] = d[1];
				c[4] = d[5];
				aw += c[0];
			}
			if (s[i] == "Right")
			{
				c[0] = d[0];
				c[2] = d[4];
				c[3] = d[1];
				c[1] = d[2];
				c[5] = d[5];
				c[4] = d[3];
				aw += c[0];
			}
			if (s[i] == "Left")
			{
				c[0] = d[0];
				c[2] = d[1];
				c[3] = d[4];
				c[1] = d[3];
				c[5] = d[5];
				c[4] = d[2];
				aw += c[0];
			}
		}
		cout << aw << endl;
	}
	
	return 0;
}