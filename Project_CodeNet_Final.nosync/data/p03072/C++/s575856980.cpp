#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	bool flag = true;
	int count = 1;
	int N, i, j;
	cin >> N;
	vector<int> height(N);
	for (i = 0; i < N; i++)
	{
		cin >> height[i];
	}
	for (i = 1; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (height[j] > height[i])
				flag = false;
		}
		if (flag == true)
			count += 1;
		flag = true;
	}
	cout << count;

	return 0;
}