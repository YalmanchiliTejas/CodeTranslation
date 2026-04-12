#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

const int nax = 3005;

ll dp[nax][nax];

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{	
		cin >> arr[i];
	}

	for (int L = n - 1; L >= 0; L--)
	{
		for (int R = L; R < n; R++)
		{
			if (R == L)
			{
				dp[L][R] = arr[L];
			}
			else
			{
				dp[L][R] = max(arr[L] - dp[L + 1][R], arr[R] - 
				dp[L][R - 1]);
			}
		}
	}

	cout << dp[0][n - 1] << endl;
}