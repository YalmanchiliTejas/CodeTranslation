#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x>0?x:-(x))

#define INF 1000000000

int array_min_max(int* p, int n,bool f)  //f: true→min false→max
{
	int tmp;

	if (f)
		tmp = INF;
	else
		tmp = 0;

	for (int i = 0; i < n; i++)
	{
		if (f)
		{
			if (p[i] < tmp)
				tmp = p[i];
		}
		else
		{
			if (p[i] > tmp)
				tmp = p[i];
		}
	}
	return tmp;
}

int main()
{
	int N;
	int H[20];
	int max = 0;
	int count = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &H[i]);
		if (H[i] >= max)
		{
			max = H[i];
			count++;
		}
	}

	printf("%d\n", count);

}