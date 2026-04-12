#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n, m;
	while(cin >> n >> m)
	{
		if(!n && !m)
		{
			break;
		}
		vector<int> Vec(n + m);
		int size = n + m;
		for(int i = 0; i < size; ++i)
		{
			cin >> Vec[i];
		}
		sort(Vec.begin(), Vec.end());
		int max = Vec[0];
		for(int i = 1; i < size; ++i)
		{

			if(max < Vec[i] - Vec[i - 1])
			{
				max = Vec[i] - Vec[i - 1];
			}
		}
		cout << max << endl;
	}
}

int main()
{
	solve();
	return(0);
}