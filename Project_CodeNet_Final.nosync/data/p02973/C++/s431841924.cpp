#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	vector<int> a;
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> t;
		t*=-1;
		int p=upper_bound(a.begin(), a.end(), t)-a.begin();
		if (p==a.size())
		{
			a.push_back(t);
		}
		else
		{
			a[p]=t;
		}
	}
	cout << a.size() << endl;
	return 0;
}