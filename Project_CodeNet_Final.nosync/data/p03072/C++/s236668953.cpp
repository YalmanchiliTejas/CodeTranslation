#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define ff first
#define ss second
#define pb push_back
#define N 505


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}

	int ans = 1, f = 0, max = h[0];
	for(int i = 1; i < n; ++i)
	{
		if(h[i] >= max)
		{
			ans++;
			max = h[i];
		}
	}
	cout << ans << "\n";
	return 0;
}