#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
//#include <vector>

using namespace std;

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x>0?x:-(x))
#define INF 1000000000

#define MOD 1000000007

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap2(double* a, double* b)
{
	double tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int gcd(int a, int b)  //最大公約数
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
	return a * b / gcd(a, b);
}

long power(long x, int n) { //x^n 計算量O(logn)
	long ans = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			ans = ans * x;
		}
		x = x * x; //一周する度にx, x^2, x^4, x^8となる
		n >>= 1; //桁をずらす n = n >> 1
	}
	return ans;
}

int choose(int n, int k) {
	return k == 0 ? 1 : (long long)choose(n - 1, k - 1) * n % MOD * power(k, MOD - 2) % MOD;
}

void bubble_sort(int a[], int n)
{
	int i, j, tmp;

	for (i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			printf("%d ", a[k]);

		for (j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
		printf("\n");
	}
}

void selection_sort(int a[], int n)
{
	int i, j, tmp, min, key;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		key = a[i];

		for (int k = 0; k < n; k++)
			printf("%d ", a[k]);

		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
				key = a[j];
			}
		}

		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;

		printf("\n");
	}

	for (int k = 0; k < n; k++)
		printf("%d ", a[k]);
}

void insertion_sort(int a[], int n)
{
	int i, j, tmp;

	for (i = 1; i < n; i++)
	{
		j = i;

		while (j >= 1 && a[j - 1] > a[j])
		{
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
			j--;
		}
	}
}

void shell_sort(int a[], int n)
{
	int h, i, j;

	for (h = 1; h < n / 9; h = h * 3 + 1)
		;

	for (; h > 0; h /= 3)
	{
		for (int k = 0; k < n; k++)
			printf("%d ", a[k]);

		for (i = h; i < n; i++)
		{
			j = i;
			while (j >= h && a[j - h] > a[j])
			{
				swap(&a[j - h], &a[j]);
				j -= h;
			}
		}
		printf("\n");
	}

	for (int k = 0; k < n; k++)
		printf("%d ", a[k]);
}

int partition(int a[], int l, int r)
{
	int i, j, pivot;

	i = l - 1;
	j = r;
	pivot = a[r];

	for (;;)
	{
		while (a[++i] < pivot)
			;
		while (i < j-- && pivot < a[j])
			;

		if (i >= j)
			break;

		swap(&a[i], &a[j]);
	}

	swap(&a[i], &a[r]);
	return i;
}

void quick_sort1(int a[], int l, int r)
{
	int v;

	if (l >= r)
		return;

	v = partition(a, l, r);

	quick_sort1(a, l, v - 1);
	quick_sort1(a, v + 1, r);
}

void quick_sort(int a[], int n)
{
	quick_sort1(a, 0, n - 1);
}

int keta(int a,int n)
{
	if (n == 1)
		return a % 10;

	for (int i = 0; i < n-1; i++)
		a /= 10;

	return a % 10;
}

int main() 
{
	int N, M, L, K;
	int a[100000];
	char S[5];

	scanf("%s", S);

	if (S[0] != S[1] || S[0] != S[2] || S[1] != S[2])
		printf("Yes");
	else
		printf("No");
}