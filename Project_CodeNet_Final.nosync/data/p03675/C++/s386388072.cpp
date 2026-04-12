#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <deque>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	bool isEven = true;
	if (n % 2 == 1)
	{
		isEven = false;
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	deque<int> Deq;
	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 1)
		{
			Deq.push_back(a[i]);
		}
		else
		{
			Deq.push_front(a[i]);
		}
	}
	if (isEven)
	{
		for (int i = n - 1; i >= 1; --i)
		{
			cout << Deq[i] << " ";
		}
		cout << Deq[0] << endl;
	}
	else
	{
		for (int i = 0; i < n - 1; ++i)
		{
			cout << Deq[i] << " ";
		}
		cout << Deq[n - 1] << endl;
	}
}

int main()
{
	solve();
	return(0);
}