#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n;
	while(cin >> n, n)
	{
		vector<int> Vec(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> Vec[i];
		}
		sort(Vec.begin(), Vec.end());
		int sum = 0;
		for(int i = 1; i < Vec.size() - 1; ++i)
		{
			sum += Vec[i];
		}
		cout << sum / (Vec.size() - 2) << endl;
	}
}

int main()
{
	solve();
	return(0);
}