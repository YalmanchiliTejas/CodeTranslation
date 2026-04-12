#include <bits/stdc++.h>

using namespace std;

int N;
int maxHeight = 0;
int cnt = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int nowHeight;
		cin >> nowHeight;

		if (nowHeight >= maxHeight)
		{
			maxHeight = nowHeight;
			cnt += 1;
		}
	}

	cout << cnt;
}