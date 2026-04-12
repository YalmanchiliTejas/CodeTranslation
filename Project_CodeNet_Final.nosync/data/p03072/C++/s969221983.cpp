#include <iostream>

using namespace std;

int main()
{
	int N;
	int temp;

	cin >> N;

	int i, j;

	int res = 0;
	bool flg;
	int max = 0;

	for (i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp >= max)
		{
			res++;
			max = temp;
		}
	}

	printf("%d", res);
	 
	return 0;
}
