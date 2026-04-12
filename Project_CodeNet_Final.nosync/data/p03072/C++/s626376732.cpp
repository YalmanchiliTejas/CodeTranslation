#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int N, H[20];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> H[i];

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		for (int j = 0; j < i; j++)
		{
			if (H[i] < H[j])
			{
				tmp++;
				break;
			}
		}

		if (tmp == 0)
			count++;
	}

	cout << count;
	return 0;
}