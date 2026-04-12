#include<iostream>
#include<string.h>
#define LEFT 1;
#define RIGHT 2;
using namespace std;

int main()
{
	string right_alpha = "yuiophjklnm";
	string str;
	char buf[34];
	while (cin >> buf && strcmp(buf,"#") != 0)
	{
		int status = 0;
		int count = 0;
		str = buf;
		for (int i = 0; i <str.size(); i++)
		{
			char c = str.at(i);
			if (right_alpha.find(c, 0) < right_alpha.size())
			{
				if (status != 0 && status == 1)count++;
				status = 2;
			}
			else
			{
				if (status != 0 && status == 2)count++;
				status = 1;
			}
		}

		cout << count << endl;
	}
	return 0;
}