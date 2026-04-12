#include <iostream>
using namespace std;
#include <bits/stdc++.h>

typedef long long ll;

vector<vector<ll>> dp_arr;
ll calcDiff(vector<ll>& arr, int i, int j)
{
	if(i > j)
		return 0;
	if(dp_arr[i][j] != -1)
		return dp_arr[i][j];
	ll a = arr[i] - calcDiff(arr, i+1,j);
	ll b = arr[j] - calcDiff(arr, i,j-1);
	dp_arr[i][j] = max(a,b);
	return dp_arr[i][j];
}

int main()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp_arr.resize(n+1, vector<ll>(n+1, -1));
	ll res = calcDiff(arr, 0, n-1);
	cout << res << endl;
	return 0;
}
