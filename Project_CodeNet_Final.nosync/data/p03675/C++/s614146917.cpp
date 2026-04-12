#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	deque<int> v;
	for (int i = 1;i <= n;i++)
	{
		int a;
		cin >> a;
		if (i % 2 == n % 2)
		{
			v.push_front(a);
		}
		else
			v.push_back(a);
	}
	for (int i = 0;i < n;i++)
	{
		cout << v.front()<<" ";
		v.pop_front();
	}
	//system("pause");
	return 0;
}