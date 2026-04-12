#include <iostream>

using namespace std;

void solve()
{
	int m;
	cin >> m;
	while(m--)
	{
		int a, year, n;
		int max = 0;
		cin >> a;
		cin >> year >> n;
		for(int i = 0; i < n; ++i)
		{
			int price = a;
			int method, charge;
			double interest;
			cin >> method;
			cin >> interest;
			cin >> charge;
			if(method == 1)
			{
				for(int j = 0; j < year; ++j)
				{
					price += price * interest - charge;
				}
				if(max < price)
				{
					max = price;
				}
			}
			else if(method == 0)
			{
				int temp = 0;
				for(int j = 0; j < year; ++j)
				{
					temp += price * interest;
					price -= charge;
				}
				price += temp;
				if(max < price)
				{
					max = price;
				}
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