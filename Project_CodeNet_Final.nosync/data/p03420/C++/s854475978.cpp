#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll res = 0;

int N, K;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;
	for (int b = K + 1; b <= N; b++) // 0 - b
	{
		int x = (N / b);
		res += x * (b - K);
		if (N % b >= K)
			res += (N % b - K + 1);
		if (K == 0)
			--res;
//		cout << "res: " << res << endl;
	}
	cout << res << endl;
	return 0;
}
