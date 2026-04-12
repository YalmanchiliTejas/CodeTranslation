#include <bits/stdc++.h>

bool solve(int, int[], int[]);

int main()
{
	int n;
	scanf("%d", &n);
	int *s{new int[n]};
	for (int i = 0; i < n; i++)
	{
		char tmp;
		scanf(" %c", &tmp);
		s[i] = tmp == 'x';
	}
	int *is_wolf{new int[n]};

	if (solve(n, s, is_wolf))
	{
		for (int i = 0; i < n; i++)
			if (is_wolf[i])
				printf("W");
			else
				printf("S");
		printf("\n");
	}
	else
		printf("-1\n");

	delete[] is_wolf;
	delete[] s;
	return 0;
}

bool solve(int n, int s[], int is_wolf[])
{
	for (int last = 0; last < 2; last++)
		for (int front = 0; front < 2; front++)
		{
			std::fill(is_wolf, is_wolf + n, 0);
			is_wolf[0] = front;
			is_wolf[n - 1] = last;
			for (int i = 0; i < n; i++)
			{
				if ((is_wolf[(i + n - 1) % n] + is_wolf[i]) % 2 != s[i])
					is_wolf[(i + 1) % n] = 1;
				else
					is_wolf[(i + 1) % n] = 0;
			}
			if ((is_wolf[0] + is_wolf[n - 1] + is_wolf[1]) % 2 == s[0]
				&& (is_wolf[0] + is_wolf[1] + is_wolf[2]) % 2 == s[1]) return true;
		}

	return false;
}