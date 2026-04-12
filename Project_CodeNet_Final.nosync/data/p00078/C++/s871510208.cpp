#define scanf_s scanf
//#define gets_s gets
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 15
#define _MAX 81
int main(void)
{
	int n;
	while (1) {
		scanf_s("%d", &n);
		if (n == 0) break;
		int x,y,m[MAX][MAX] = { 0 };
		x = n / 2; y = n / 2 + 1;
		m[x][y] = 1;
		for (int i = 2; i <= n*n; ++i) {
			++x; ++y;
			if (m[x % n][y % n] != 0) {
				--x; ++y;
				m[x % n][y % n] = i;
			}
			else m[x % n][y % n] = i;
		}
		for (int i = 0; i < n*n; ++i) {
			printf("%4d", m[i % n][i / n]);
			if (i % n == n - 1) printf("\n");
		}
	}
}