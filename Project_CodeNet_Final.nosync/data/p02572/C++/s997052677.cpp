#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define int long long
#define sz(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;



signed main()
{
	int n;
	cin >> n;
	int a[n];
	rep(i,0,n) cin >> a[i];

	int dp[n];
	dp[n-1] = 0;

	for(int i=n-2;i>=0;i--)
	{
		dp[i] = (a[i+1] + dp[i+1])%hell;
	}
	int ans = 0;
	rep(i,0,n)
	{
		ans = (ans%hell+(a[i]%hell*dp[i]%hell)%hell)%hell;

	}
	cout << ans <<endl;


}
 
	
		

