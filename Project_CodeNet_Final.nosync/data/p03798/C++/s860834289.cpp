#include <stdio.h>
#include <string.h>
#include <iostream>

int N;
char s[114514];
bool P, Q, R, X, s_P, s_Q;
std::string ans;

int main(void)
{
	scanf("%d%s", &N, s);

	for (int i = 0; i < 4; ++i)
	{
		P = i & 2, Q = i & 1;
		s_P = P, s_Q = Q;
		for (int j = 0; j < N; ++j)
		{
			if (Q == true)
			{
				ans += "S";
			}
			else
			{
				ans += "W";
			}
			X = (s[((j % N + N) % N)] == 'o');
			R = P ^ Q ^ X;
			P = Q;
			Q = R;
		}
		if (s_P == P && s_Q == Q)
		{
			break;
		}
		ans = "\0";
	}

	if (ans[0] != '\0')
	{
		std::cout << ans << std::endl;
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}