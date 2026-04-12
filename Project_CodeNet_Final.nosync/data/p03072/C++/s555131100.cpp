#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <functional>
#include <string.h>

using namespace std;
typedef pair<long long, long long> P;


void solve()
{
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> H[i];
	}
	int ans = 1;
	for (int i = 1; i < N; ++i)
	{
		bool flag = true;
		for (int j = 0; j < i; ++j)
		{
			if (H[j] > H[i])
			{
				flag = false;
			}
		}
		if (flag)
		{
			++ans;
		}
	}
	cout << ans << endl;
}

int main()
{
	solve();
	return(0);
}