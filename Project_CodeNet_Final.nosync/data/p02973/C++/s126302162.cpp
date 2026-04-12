// E - Sequence Decomposing - atcoder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> set;
	int n ,x;
	cin >> n;

	cin >> x;
	set.insert(x);

	for (int i = 0; i < n -1; i++)
	{
		cin >> x;
		
		if (set.lower_bound(x) != set.begin())
			set.erase(--set.lower_bound(x));
		set.insert(x);
	}
	cout << set.size();
}
