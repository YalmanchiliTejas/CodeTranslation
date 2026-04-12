#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;


const int mod = 1000000007;

/* Using gfg Code */

long long moduloMultiplication(long long a,
                               long long b,
                               long long mod)
{
	long long res = 0;
	a %= mod;

	while (b)
	{

		if (b & 1)
			res = (res + a) % mod;

		a = (2 * a) % mod;

		b >>= 1;
	}

	return res;
}



int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	int T = 1;

	while (T--)
	{

		int n;

		cin >> n;

		int arr[n];


		for (int i = 0; i < n; ++i)
			cin >> arr[i];


		int prefix_sum = 0;

		for (int i = 0; i < n; ++i)
		{
			prefix_sum += arr[i];

			prefix_sum = prefix_sum % mod;
		}



		int ans = 0;



		for (int i = 0; i < n - 1; ++i)
		{

			prefix_sum -= arr[i];

			if (prefix_sum <= 0) prefix_sum += mod;

			ans += prefix_sum * arr[i];

			ans = ans % mod;


		}


		cout << ans << endl;



	}


	return 0;


}