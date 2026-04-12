#include <iostream>

using namespace std;

void solve()
{
	int m;
	cin >> m;
	while(m--)
	{
		long long money;
		int year;
		int n;
		cin >> money >> year >> n;
		long long max_result = 0;
		for(int i = 0; i < n; ++i)
		{
			int method;
			double profit;
			int charge;
			cin >> method >> profit >> charge;
			long long fortune = money;
			if(method == 0)
			{
				int sum = 0;
				for(int j = 0; j < year; ++j)
				{
					sum += fortune * profit;
					fortune -= charge; 
				}
				if(max_result < sum + fortune)
				{
					max_result = sum + fortune;
				}
			}
			else if(method == 1)
			{
				for(int j = 0; j < year; ++j)
				{
					fortune += fortune * profit;
					fortune -= charge;
				}
				if(max_result < fortune)
				{
					max_result = fortune;
				}
			}
		}
		cout << max_result << endl;
	}
}

int main()
{
	solve();
	return(0);
}