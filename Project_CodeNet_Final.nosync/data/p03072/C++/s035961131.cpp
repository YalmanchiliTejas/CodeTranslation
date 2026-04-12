#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> array(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> array[i];
	}

	int preMaxValue = -1;
	int resultValue = 0;
	for (int i = 0; i < N; ++i)
	{
		if (preMaxValue <= array[i])
		{
			preMaxValue = array[i];
			++resultValue;
		}

	}
	cout << resultValue << endl;

	return 0;
}
