#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,t;
	vector <int> v;
	long long int sum = 0;
	long long int res = 0;
	const long long int MOD = 1e9 + 7;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		v.push_back(t);
	}

	for(int i=0;i<n;i++)
	{
		res = ((res%MOD) + (sum*v[i]%MOD)%MOD)%MOD;
		res%=MOD;
		sum = ((sum%MOD) + (v[i]%MOD)%MOD)%MOD;
		sum%=MOD;
	}

	cout << res << '\n';
	
	return 0;	
}