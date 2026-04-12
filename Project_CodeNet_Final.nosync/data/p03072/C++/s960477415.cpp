#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<list>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int max = 0;
	int output = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		if (max <= temp)
		{
			max = temp;
			output++;
		}
	}
	cout << output << endl;
	return 0;
}