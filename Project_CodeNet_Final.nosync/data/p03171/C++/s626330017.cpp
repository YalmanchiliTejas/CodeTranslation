#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
const int N = 3000, M = 7 + 1e9;
int n, a[N];
ll dp[N][N][2];
ll cal(int i, int j, int p){
	if( i == j ){
		if(p)
			return a[i];
		return -a[i];
	}
	ll &ret =  dp[i][j][p];
	if(~ret)
		return ret;
	if(p==0){
		return ret = min(cal(i+1, j, !p)-a[i], cal(i, j-1, !p)-a[j]);
	}else{
		return ret = max(cal(i+1, j, !p)+a[i], cal(i, j-1, !p)+a[j]);
	}
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	f(i, 0, n)
		cin >> a[i];
	cout << cal(0, n-1, 1);
 
}