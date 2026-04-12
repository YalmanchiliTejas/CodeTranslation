#include "stdio.h"

int n;
char S[51][60] = {};
int num[123] = {};
int num2[123] = {};

int main() {
	scanf("%d", &n);
	for (int i = 97; i <= 122; i++) {
		num[i] = 3000;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", S[i]);
		for (int i = 97; i <= 122; i++) {
			num2[i] = 0;
		}
		for (int j = 0; j <= 50; j++) {
			if (S[i][j] == NULL)break;
			num2[S[i][j]]++;
		}
		for (int j = 97; j <= 122; j++) {
			if (num2[j]<num[j])num[j] = num2[j];
		}
	}
	for (int i = 97; i <= 122; i++) {
		if (num[i]<=2500) {
			for (int j = 1; j <= num[i]; j++) {
				printf("%c", i);
			}
		}
	}
}