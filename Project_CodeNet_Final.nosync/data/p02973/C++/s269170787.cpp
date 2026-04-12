#include <iostream>
#include <string>

#include <set>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = stoi(str);
	multiset<int> vals;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		int x = stoi(str);

		auto p = vals.lower_bound(x);
		if (!vals.empty() && p != vals.cbegin())
		{
			--p;
			vals.erase(p);
		}
		vals.insert(x);
	}

	//for (const auto& x : vals)
	//{
	//	cout << x << endl;
	//}

	cout << vals.size() << endl;

	return 0;
}