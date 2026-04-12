#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x>0?x:-(x))

#define INF 1000000000

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int gcd(int a, int b)
{
	if (a < b)
		swap(&a, &b);

	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a*b/gcd(a, b);
}

void bubble_sort(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j] > p[j + 1])
				swap(&p[j], &p[j + 1]);
		}
	}
}

int array_max(int* p, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] > max)
			max = p[i];
	}
	return max;
}

int binary_search(int* p, int key, int n)
{
	int low = 0, high = n - 1;
	int middle;

	while (low <= high)
	{
		middle = (low + high) / 2;

		//printf("low %d  middle %d  high %d\n", low, middle, high);

		//for (int i = 0; i < n; i++)
		//{
		//	if (i == middle)
		//		printf(" ^ ");
		//	else if (i == low)
		//		printf(" [ ");
		//	else if (i == high)
		//		printf(" ] ");
		//	else if (i == middle)
		//		printf(" ^ ");
		//	else
		//		printf("   ");
		//}
		//printf("\n");

		if (key == p[middle])
			return key;
		else if (key < p[middle])
			high = middle - 1;
		else if (key > p[middle])
			low = middle + 1;
	}

	//printf("low %d  middle %d  high %d\n", low, middle, high);
	return -1;
}

int main()
{
	int H, W;

	char a[100][100];
	int h[100] = { 0 }, w[100] = { 0 };

	scanf("%d%d", &H, &W);

	for (int i = 0; i < H; i++)
		scanf("%s", a[i]);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (a[i][j] == '#')
			{
				h[i] = 1;
				w[j] = 1;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		if (h[i] == 1)
		{
			for (int j = 0; j < W; j++)
			{
				if (w[j] == 1)
					printf("%c", a[i][j]);

			}
		}
			printf("\n");
	}


	return 0;
}