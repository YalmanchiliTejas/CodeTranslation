#include<iostream>
#include <string> 
#include <vector>  
#include<math.h>

#define INF 1000000000
using namespace::std;

void m_sort(int a[], int tmp[], int left, int right);
void m_sort(int a[], int tmp[], int left, int right);
void sort(int a[], int total) {
	int tmp;
	for (int i = 0; i < total; i++) {
		for (int j = i + 1; j < total; j++) {
			if (a[i] < a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

}

void mergeSort(int a[], int tmp[], int size)
{
	m_sort(a, tmp, 0, size - 1);
}
void merge(int a[], int tmp[], int left, int mid, int right)
{
	int i, left_end, num_elements, tmp_pos;

	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1; // 要素 

	while ((left <= left_end) && (mid <= right))
	{
		if (a[left] <= a[mid])
		{
			tmp[tmp_pos] = a[left];
			tmp_pos = tmp_pos + 1;
			left = left + 1;
		}
		else
		{
			tmp[tmp_pos] = a[mid];
			tmp_pos = tmp_pos + 1;
			mid = mid + 1;
		}
	}


	while (left <= left_end)
	{
		tmp[tmp_pos] = a[left];
		left = left + 1;
		tmp_pos = tmp_pos + 1;
	}

	while (mid <= right)
	{
		tmp[tmp_pos] = a[mid];
		mid = mid + 1;
		tmp_pos = tmp_pos + 1;
	}


	for (i = 0; i <= num_elements; i++)
	{
		a[right] = tmp[right];
		right = right - 1;
	}
}
void m_sort(int a[], int tmp[], int left, int right)
{
	int mid;

	if (right > left)
	{
		mid = (right + left) / 2;
		m_sort(a, tmp, left, mid);
		m_sort(a, tmp, mid + 1, right);

		merge(a, tmp, left, mid + 1, right);
	}
}


long Lmax(long x, long y) {
	if (x > y)return x;
	return y;
}

int max(int x, int y) {
	if (x > y)return x;
	return y;
}

long Lmin(long x, long y) {
	if (x < y)return x;
	return y;
}


int min(int x, int y) {
	if (x < y)return x;
	return y;
}

int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

bool c;
int point,N;
int H,X,Y ,Z,T, R, G, M, K, W, t[101], v[101], ans, now;
char S,s;

int main() {
	cin >> X >> Y >> Z;
	if ((X - Z) % (Z + Y) != 0) {
		X -= (X - Z) % (Z + Y);
	}
	ans = (X - Z) / (Z + Y);
	cout << ans << endl;
	return 0;
}


