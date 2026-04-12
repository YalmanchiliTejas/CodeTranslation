#define scanf_s scanf
//#define gets_s gets
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 30
int main(void)
{
	int p[101], s[MAX + 1] = { 0 }, a, b, q;
	while(1){
		scanf_s("%d,%d", &a, &b);
		if (a == 0 && b == 0) break;
		s[b] = true;
		p[a] = b;
	}
	while (scanf_s("%d", &q) != EOF) {
		for (int i = MAX, k = 0; i >= 0; --i) {
			if (s[i]) ++k;
			if (i == p[q]) {
				printf("%d\n", k);
				break;
			}
		}
	}

}