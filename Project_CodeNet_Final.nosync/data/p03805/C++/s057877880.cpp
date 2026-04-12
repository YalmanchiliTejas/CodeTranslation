#include <stdio.h>
#include <string.h>

int N, M, a[100], b[100];
bool IsAlreadyWalk[100][100];
bool IsAlreadyReach[100];
int ans;

int f(int pos, int cou)
{
	int res = 0;
	if (cou == N)
	{
		return 1;
	}
	for (int i = 0; i < M; ++i)
	{
		if (a[i] == pos)
		{
			if (IsAlreadyWalk[a[i]][b[i]] == false
				&& IsAlreadyReach[b[i]] == false)
			{
				IsAlreadyWalk[a[i]][b[i]] = true;
				IsAlreadyReach[b[i]] = true;
				res += f(b[i], cou + 1);
				IsAlreadyWalk[a[i]][b[i]] = false;
				IsAlreadyReach[b[i]] = false;
			}
		}
		if (b[i] == pos)
		{
			if (IsAlreadyWalk[a[i]][b[i]] == false
				&& IsAlreadyReach[a[i]] == false)
			{
				IsAlreadyWalk[a[i]][b[i]] = true;
				IsAlreadyReach[a[i]] = true;
				res += f(a[i], cou + 1);
				IsAlreadyWalk[a[i]][b[i]] = false;
				IsAlreadyReach[a[i]] = false;
			}
		}
	}
	return res;
}

int main(void)
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) { scanf("%d%d", &a[i], &b[i]); }

	memset(IsAlreadyWalk, false, sizeof(IsAlreadyWalk));
	memset(IsAlreadyReach, false, sizeof(IsAlreadyReach));
	IsAlreadyReach[1] = true;

	printf("%d\n", f(1, 1));
	return 0;
}