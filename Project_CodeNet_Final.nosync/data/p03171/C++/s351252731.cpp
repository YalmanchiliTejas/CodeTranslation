#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define test() ll t;cin>>t;for(ll test = 1;test<=t;test++)
#define f first
#define s second
#define pb push_back
#define ins insert
#define nl cout<<"\n"
#define P 1000000007
#define N 3005
#define MOD(x) ((x%P)+P)%P
#define show(x) cout<<x<<" "
#define vec(v) loop(i,0,v.size()) show(v[i]); nl

ll dp[N][N];
bool vis[N][N];
ll arr[N];

ll solve(int i, int j)
{
	if(vis[i][j])
		return dp[i][j];

	vis[i][j] = 1;

	if(i==j)
	{
		dp[i][j] = arr[i];
		return arr[i];
	}

	dp[i][j] =  max( arr[i] - solve(i+1,j) , arr[j] - solve(i,j-1));

	return dp[i][j];
}

int main()
{
	fastio();

	ll n;
	cin>>n;

	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));

	loop(i,0,n)
		cin>>arr[i];

	ll diff = solve(0,n-1);
	cout<<diff,nl;

	// int i = 0, j = n-1;

	// while(i<=j)
	// {
	// 	if(diff == (arr[i] - dp[i+1][j]))
	// 	{
	// 		diff = dp[i+1][j];
	// 		cout<<i<<" ";
	// 		i++;
	// 	}
	// 	else
	// 	{
	// 		diff = dp[i][j-1];
	// 		cout<<j<<" ";
	// 		j--;
	// 	}
	// }



	//cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}