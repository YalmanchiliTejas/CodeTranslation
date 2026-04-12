#include<bits/stdc++.h>
using namespace std;
void solve();
int main()
{
//	freopen("SNOOKER.inp","r",stdin);
//	freopen("SNOOKER.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}

using ll =  long long;
#define endl "\n"
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define what_is(x)  cerr << #x << " is :" << (x) << endl
#define what_are(x,y) cerr << #x <<" is : " << (x) <<" ; " << #y <<" is: " <<y << endl
#define pii pair<int,int>
#define fi first
#define se second

const int MOD =  1e9+7;
const int inf = INT_MAX;
const int MAX_N = 1e5 + 7;

int n;
ll dp[3007][3007], a[3007] ,total = 0;

void solve()
{
	
	
	cin >> n;
	for(int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		total += a[i];
	}
	
	for(int l = n; l > 0; l --)
	{
		for(int r = l; r <= n; r ++)
		{
			if(l == r) dp[l][r] = a[l];
			else if(l +1 == r) dp[l][r] = max(a[l], a[r]);
			else
			{
				dp[l][r] = max(a[l] + min(dp[l+2][r], dp[l+1][r-1]) ,
								a[r] + min(dp[l][r-2], dp[l+1][r-1])
								);
			}
		}
	}
	
	cout << 2*dp[1][n] - total ;
}
/*----------------------------------------------------------------------

-----------------------------------------------------------------------*/