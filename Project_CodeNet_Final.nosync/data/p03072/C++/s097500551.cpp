#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n,sum,max,tmp;
	cin >> n;
	sum = 0;
	max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp >= max)
		{
			sum++;
			max = tmp;
		}
	}
	cout << sum << endl;
	return 0;
}