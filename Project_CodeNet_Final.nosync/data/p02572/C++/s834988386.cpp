#include<bits/stdc++.h>

using namespace std;

int n;
int a[200010];
long long s[200010];
long long ans;
const int mod = 1e9 + 7;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	for(int i = 1; i <= n-1; i++)
	{
		ans = (ans + (s[n] - s[i]) % mod * a[i] % mod) % mod;
	}
	cout << ans << endl;
}