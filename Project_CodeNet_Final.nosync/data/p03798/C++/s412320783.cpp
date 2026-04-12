#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <map>
#include <math.h>
#pragma warning(disable : 4996)

#define MAX_N 100000

char S[MAX_N+1];
char R[MAX_N+1];

int main(void) {
	int n;
	scanf("%d", &n);
	scanf("%s", &S[0]);

	for (int f = 0; f < 2; ++f) {
		for (int s = 0; s < 2; ++s) {
			// 0:Sheep 1:Wolf
			int n0 = f;
			int n1 = s;
			R[0] = (f == 0) ? 'S' : 'W';
			R[1] = (s == 0) ? 'S' : 'W';
			int n2;
			for (int i = 2; i <= n; ++i) {
				if (n1 == 0) {
					if (S[i - 1] == 'o') {
						n2 = n0;
					}
					else {
						n2 = 1 - n0;
					}
				}
				else {
					if (S[i - 1] == 'o') {
						n2 = 1 - n0;
					}
					else {
						n2 = n0;
					}
				}
				n0 = n1;
				n1 = n2;
				R[i%n] = (n2 == 0) ? 'S' : 'W';
			}
			R[n] = '\0';
			bool success = false;
			if (n2 == f) {
				if (f == 0) {
					if (S[0] == 'o') {
						success = R[1] == R[n-1];
					}
					else {
						success = R[1] != R[n - 1];
					}
				}
				else {
					if (S[0] == 'o') {
						success = R[1] != R[n - 1];
					}
					else {
						success = R[1] == R[n - 1];
					}
				}
			}
			if (success) {
				printf("%s", R);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}
