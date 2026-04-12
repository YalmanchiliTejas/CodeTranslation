#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0);cin.tie(0);
typedef long long ll;


int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif	
	
	fastio;

	int n;
	cin >> n;
	ll arr[n], sum = 0, prod = 0, mod = 1000000007;

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	for(int i = 0; i < n; i++)
	{
		prod = prod % mod + ((arr[i] % mod * ((sum - arr[i]) % mod)) % mod) % mod;
		sum -= arr[i];
	}

	cout << prod;
	return 0;

}