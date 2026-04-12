// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 1e9+7, M = 2e5+9;
int a[M], n;
ll pre[M];
ll get_ans()
{
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)ans = (ans + a[i] * a[j])%N;
	}
	return ans % N;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	pre[0] = a[0];
	for (int i = 1; i < n; i++)pre[i] = (pre[i-1] + a[i])%N;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll sum = pre[n-1] - pre[i];
		sum = (sum + N)%N; 
		ans = (ans + 1LL * a[i] * sum)%N;
	}
	cout << ans << '\n';
	
	
	
}
