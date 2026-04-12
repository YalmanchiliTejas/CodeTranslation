#include <iostream>

using namespace std;

void solve()
{
	int am, pm;
	while(cin >> am >> pm)
	{
		if(!am && !pm)
		{
			break;
		}
		int sum[5] = {0};
		sum[0] = am + pm;
		int index = 0;
		int max = sum[0];
		for(int i = 1; i < 5; ++i)
		{
			cin >> am >> pm;
			sum[i] = am + pm;
			if(sum[i] > max)
			{
				max = sum[i];
				index = i;
			}
		}
		printf("%c %d\n", 'A' + index, max);
	}
}

int main()
{
	solve();
	return(0);
}