/*suri_kumkaran*/

#include <bits/stdc++.h>

using namespace std;

#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define MP make_pair
#define EB emplace_back
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 998244353
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

typedef long long int64;
typedef vector<int> VI64;
typedef vector<pair<int,int>> VII64;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;

int a[3001];
int dp[3001][3001];
int32_t main()
{
	IOS;
	int T=1;
	//cin>>T;
	while(T--)
	{
		int n,s,i,j;
		cin>>n>>s;
		for(i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=s;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(j-a[i]>=0)
				{
					dp[i][j]+=dp[i-1][j-a[i]];
					dp[i][j]%=MOD;
				}
			}
			dp[i][a[i]]+=i;
			dp[i][a[i]]%=MOD;
			ans=(ans+dp[i][s])%MOD;
		}
		cout<<ans<<endl;
	}

	return 0;
}