#include <iostream>

using namespace std;

int mountain_n;
int mountain_h[100];
int cansee_num;

inline void CheckCanSee()
{
	for (int count_i = 0; count_i < mountain_n; count_i++)
	{
		bool cansee = true;

		for (int j = 0; j < count_i; j++)
		{
			if (mountain_h[j] > mountain_h[count_i])
			{
				cansee = false;
				break;
			}
		}

		if (cansee == true)
		{
			cansee_num++;
		}
	}
}

int main()
{
	cin >> mountain_n;
	for (int i = 0; i < mountain_n; i++)
		cin >> mountain_h[i];

	CheckCanSee();

	cout << cansee_num;

	return 0;
}