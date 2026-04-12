#include<bits/stdc++.h>
using namespace std;
#define loop(i,x,z) for (int i=x;i<z;i++)
using ll = long long;
const int M = 1000000007;
ll n, A[3001], dp[3002][3002];
ll pref[3002], suf[3002];
ll play(int x, int y)
{
	if (x == y)
	{
		dp[x][y] = A[x];
		return 0;
	}
	if (dp[x][y]) return (pref[n]-pref[x-1]-suf[y+1]-dp[x][y]);
	dp[x][y]= max(A[x] + play(x + 1, y), A[y] + play(x, y - 1));
	return pref[n] - pref[x - 1] - suf[y + 1] - dp[x][y];
}
int main()
{
	cin >> n;
	loop(i, 1, n + 1)
	{
		cin >> A[i];
		pref[i] += A[i]+pref[i-1];
	}
	loop(i, 1, n + 1)
	{
		suf[n + 1 - i] += A[n + 1 - i]+suf[n - i+2];
	}
	cout<<pref[n]-(ll)2*play(1, n);
}

