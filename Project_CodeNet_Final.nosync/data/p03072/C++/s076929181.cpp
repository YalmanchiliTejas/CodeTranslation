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
	int max = 0;

	for (i = 0; i < N; i++)
	{
		cin >> H[i];
		if (H[i] >= max)
		{
			res++;
			max = H[i];
		}
	}

	printf("%d", res);
	 
	return 0;
}
