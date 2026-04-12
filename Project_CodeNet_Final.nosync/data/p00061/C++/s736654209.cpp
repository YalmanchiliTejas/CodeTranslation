#include <stdio.h>
using namespace std;

int main()
{
	int data[101] = {};
	int rank[101] = {};
	int n, p;
	int r = 1;
	bool flag = false;

	while (true)
	{
		scanf("%d,%d", &n, &p);
		if (n + p == 0) break;
		data[n] = p;
	}
	for (int i = 30; i >= 0; i--)
	{
		flag = false;
		for (int j = 1; j <= 100; j++)
		{
			if (data[j] == i && rank[j] == 0)
			{
				flag = true;
				rank[j] = r;
			}
		}
		if (flag) r++;
	}

	while (true)
	{
		if (scanf("%d", &n) == -1) break;
		printf("%d\n", rank[n]);
	}

	return 0;
}