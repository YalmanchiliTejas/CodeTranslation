#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define fo(i, n) for(int i = 1; i <= n; ++i)
#define rep(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 200200;
const int mod = 1e9 + 7;
const ll INF = 1e18;
int n,m,ok[20][20],a[20];
ll dp[1<<10][10];
int ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	fo(i,m)
	{
		int x,y;
		cin>>x>>y;
		ok[x][y]=1;
		ok[y][x]=1;
	}
	for(int i=0;i<(1<<n);++i)
		for(int j=0;j<n;++j)
			dp[i][j]=0;
	dp[1][0]=1;
	for(int i=0;i<(1<<n);++i)
		for(int j=0;j<n;++j)
			if(!((1<<j)&i))	
				for(int k=0;k<n;++k)
					if((1<<k)&i)
						if(ok[k+1][j+1])
							dp[i+(1<<j)][j]+=dp[i][k];
	for(int i=1;i<n;++i)	
		ans+=dp[(1<<n)-1][i];
	cout<<ans;
	return 0;	
}