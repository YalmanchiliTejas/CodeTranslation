#include <iostream>
using namespace std;

int main()
{
	int N, T, E, x[100];
	cin >> N >> T >> E;
	for (int i = 0; i < N; ++i) cin >> x[i];
	for (int i = T-E; i <= T+E; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i % x[j] == 0)
			{
				cout << j+1 << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}