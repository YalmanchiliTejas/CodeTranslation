#include <stdio.h>

char s[200000];

int main(void) {

	int n;//食べた回数//
	int m;//食べた回数を15で割った商//
	int money;//今までに払った金額//

	scanf("%d", &n);

	m = n / 15;

	money = 800 * n - 200 * m;

	printf("%d", money);



	return 0;
}
