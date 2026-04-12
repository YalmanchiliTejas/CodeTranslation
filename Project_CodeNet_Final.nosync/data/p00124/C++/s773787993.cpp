#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef pair<string, int> P;
void solve()
{
	int n;
	bool flag = false;
	while(cin >> n, n)
	{
		if(flag)
		{
			cout << endl;
		}
		flag = true;
		vector<P> data(n);
		int temp[3];
		for(int i = 0; i < n; ++i)
		{
			cin >> data[i].first >> temp[0] >> temp[1] >> temp[2];
			data[i].second = temp[0] * 3 + temp[2];
		}
		
		for(int i = 0; i < n; ++i)
		{
			for(int j = n - 1; j > i; --j)
			{
				if(data[j].second > data[j - 1].second)
				{
					P a = data[j];
					data[j] = data[j - 1];
					data[j - 1] = a;
				}
			}
		}
		for(int i = 0; i < n; ++i)
		{
			cout << data[i].first << "," << data[i].second << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}