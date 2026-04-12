#include <stdio.h>
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	if (N==M) printf("Yes");
	else if (M<N) printf("No");
	
	return 0;
}