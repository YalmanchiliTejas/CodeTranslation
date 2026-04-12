#include <bits/stdc++.h> //I - Grid 1
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 3010;
const int mod = 1e9 + 7;
typedef long long int ll;


ll dp[maxn][maxn],v[maxn];
ll sum[maxn];
int n,m,ans;


ll solve(int i,int j)
{
	if(i == j) return dp[i][j] = v[i];
	if(dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = sum[j] - sum[i-1] - min(solve(i+1,j),solve(i,j-1));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;

	for(int i=0;i<maxn;++i)
		for(int j=0;j<maxn;++j)
			dp[i][j] = -1;

	for(int i=1;i<=n;++i)
	{		
		cin>>v[i];
		sum[i] = sum[i-1] + v[i];
	}

	ll X = solve(1,n);
	ll Y = sum[n] - X;

	cout<<X - Y<<"\n";
}