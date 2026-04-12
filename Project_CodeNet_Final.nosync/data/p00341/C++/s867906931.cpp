#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int length[12];

	int i, j;

	for (i = 0; i < 12; i++)
	{
		cin >> length[i];
	}

	sort(length, length + 12);

	int check = 0;
	for (i = 0; i < 12; i += 4)
	{
		if (length[i] == length[i + 1] && length[i] == length[i + 2] && length[i] == length[i + 3])
		{
			check++;
		}
	}

	if (check == 3)
	{
		cout << "yes\n";
	}
	else
	{
		cout << "no\n";
	}

	return 0;
}
