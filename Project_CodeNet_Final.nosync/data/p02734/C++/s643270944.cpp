#include<bits/stdc++.h>
#define ll  long long
#define ff first
#define ss second
#define pb push_back
#define pp pair<ll,ll>
#define maxn 3005
#define db double
#define mod 998244353
using namespace std;
ll arr[maxn];
ll dp[maxn][maxn];
void solve()
{
	ll n,s;
	cin >> n >> s;
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=n;i++)
		cin >> arr[i];
	for(ll i=0;i<=n;i++)
		dp[i][0]=i;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=s;j++)
		{
			dp[i][j] = dp[i-1][j];
			if(arr[i] == j)
				dp[i][j]=(dp[i][j]+i)%mod;
			else if(arr[i] < j)
				dp[i][j]= (dp[i][j]+dp[i-1][j-arr[i]])%mod;
		}
		ans = (ans+dp[i][s])%mod;
	}
	cout << ans;
}
int main()
{
	ll t=1,i=1;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
    std::cout.precision(10);
    std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 
	//cin >> t;
	//cin >> n;
	while(i<=t)
	{
		solve();
		i++;
	}
	return 0;
}