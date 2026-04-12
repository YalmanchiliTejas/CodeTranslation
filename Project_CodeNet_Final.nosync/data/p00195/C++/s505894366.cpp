#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;
char c[5] = {'A', 'B', 'C', 'D', 'E'};

void solve()
{
	vector<int> Vec(5);
	int a, b;
	while(cin >> a >> b, a || b)
	{
		Vec[0] = a + b;
		for(int i = 1; i < 5; ++i)
		{
			cin >> a >> b;
			Vec[i] = a + b;
		}
		int max_shop = 0;
		int max_sell_num = Vec[0];
		for(int i = 0; i < 5; ++i)
		{
			if(max_sell_num < Vec[i])
			{
				max_sell_num = Vec[i];
				max_shop = i;
			}
		}
		cout << c[max_shop] << " " << Vec[max_shop] << endl;
	}
}

int main()
{
	solve();
	return(0);
}