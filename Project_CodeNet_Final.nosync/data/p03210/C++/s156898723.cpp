// ConsoleApplication11.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdio.h"

int main()
{
	int N;
	int a;
	int i;
	i = 1;
	a = 1;
	scanf("%d", &N);
	if (N == 3 || N == 5 || N == 7){

		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	return 0;
}