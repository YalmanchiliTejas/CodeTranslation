#include <stdio.h>

int main(void)
{
	int N;
	int *H;
	scanf("%d", &N);
	H = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &H[i]);

	int cnt =1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (H[i] < H[j])
				break;

			if (j == i - 1)
				cnt++;
		}
	}

	printf("%d", cnt);
	rewind(stdin);
	getchar();

	delete[] H;
	return 0;
}