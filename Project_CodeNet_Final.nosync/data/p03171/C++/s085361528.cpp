#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define ll long long
#define ld long double
#define fi first
#define se second
#define INF 1e18

const ll mod = 1000000000+7;
const int N = 3000+5;

ll dp[N][N];
ll a[N];

ll go(int i, int j)
{
	if(i==j)return a[i];
	if(dp[i][j]!=-INF)return dp[i][j];
	return dp[i][j] = max(a[i]-go(i+1,j),a[j]-go(i,j-1));
}

main()
{ 
	SPEED;
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0 ;i<=n; i++)
	{
		for(int j = 0; j<=n; j++)
		{
			dp[i][j] = -INF;
		}
	}
	cout << go(1,n) << endl;
	
}