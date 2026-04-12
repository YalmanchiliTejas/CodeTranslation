#include <bits/stdc++.h>

using namespace std;

unsigned long long  runrun(int L, unsigned long long  i)
{
	unsigned long long size = pow(2, L + 1) - 3;
	if (L == 0)
	{
		return 1;
	}
	else if (i == 0)
	{
		return 0;
	}
	else if (i == size +1)
	{
		return runrun(L-1,size-1) + 1;
	}
	else if (i == 2 * size + 2)
	{
		return 2*runrun(L-1,size-1)+1;
	}
	else if (0 < i && i < size +1)
	{
		return  runrun(L - 1, i - 1);
	}
	else if (size + 1 < i && i < 2 * size + 2)
	{
		return  runrun(L - 1, size -1) + 1 + runrun(L - 1, i - size - 2);
	}
}

int main()
{
	int L;
	cin >> L;
	unsigned long long  X;
	cin >> X;
	cout << runrun(L,X-1);
	return 0;
}