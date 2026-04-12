#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <list>

using namespace std;

int main()
{
	int N;
	vector<int> H;

	cin >> N;

	int i, j;
	H.resize(N);

	int res = 0;
	bool flg;
	for (i = 0; i < N; i++)
	{
		cin >> H[i];
		flg = false;
		for (j = 0; j < i; j++)
		{
			if (H[j] <= H[i])
				continue;
			else
			{
				flg = true;
				break;
			}
		}

		if (!flg)
			res++;
	}

	printf("%d", res);
	 
	return 0;
}
