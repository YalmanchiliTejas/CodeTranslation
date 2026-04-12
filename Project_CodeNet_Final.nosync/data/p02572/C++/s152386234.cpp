#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int N;
	cin >> N;

	int sum = 0;

	int res = 0;

	for(int i = 0 ; i < N ; i++)
	{
		int n;
		cin >> n;

		res = (res + sum*n)%MOD;

		sum = (sum + n)%MOD;
	}    

	cout << res << '\n';

    return 0;
}