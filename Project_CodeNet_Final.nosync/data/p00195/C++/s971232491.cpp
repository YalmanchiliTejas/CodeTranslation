#include<iostream>

using namespace std;

struct sct
{
	char s;
	int s1;
	int s2;
};

int main()
{
	while(true)
	{
		sct info[5], max;

		for(int i = 0; i < 5; i++)
		{
			cin >> info[i].s1 >> info[i].s2;
			info[i].s = 65 + i;

			if(info[0].s1 == 0 && info[0].s2 == 0)
			{
				return false;
			}
		}

		max = info[0];

		for(int i = 1; i < 5; i++)
		{
			if(max.s1 + max.s2 < info[i].s1 + info[i].s2)
			{
				max = info[i];
			}
		}

		cout << max.s << ' ' << max.s1 + max.s2 << endl;
	}
}