#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	LLONG N, K; cin >> N >> K;
	if (K == 0)
	{
		cout << N * N << endl;
	}
	else 
	{
		LLONG ans = 0;
		for (int b = K + 1; b <= N; ++b)
		{
			ans += (N / b) * (b - K);
			if (N % b != 0 && N % b >= K)
			{
				ans += N % b - K + 1;
			}
		}
		cout << ans << endl;
	}
}