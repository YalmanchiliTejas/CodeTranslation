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

	int ans = 1, f = 0;
	for(int i = 1; i < n; ++i)
	{
		f = 1;
		for(int j = 0; j < i; ++j)
			if(h[i] < h[j])
				f = 0;
		if(f)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}