#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int N, T, E;
	cin >> N >> T >> E;
	int min = T - E;
	int max = T + E;
	vector<int> time(N);
	for(int i = 0; i < N; ++i)
	{
		cin >> time[i];
	}
	bool okFlag = false;
	for(int i = 0; i < N; ++i)
	{
		if(okFlag)
		{
			break;
		}
		okFlag = false;
		int sum = time[i];
		while(sum <= max)
		{
			if(min <= sum)
			{
				cout << i + 1 << endl;
				okFlag = true;
				break;
			}
			sum += time[i];
		}
	}
	if(!okFlag)
	{
		cout << -1 << endl;
	}
}

int main()
{
	solve();
	return(0);
}