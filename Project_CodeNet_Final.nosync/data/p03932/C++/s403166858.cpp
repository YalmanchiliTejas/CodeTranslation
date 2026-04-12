#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll a[211][211];
int h, w;
ll dp[402][202][202];

void amax(ll &x, ll y)
{
	x=max(x,y);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>h>>w;
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i = 2; i <= h + w; i++)
	{
		for(int j = 1; j <= h; j++)
		{
			for(int k = 1; k <= h; k++)
			{
				if(j>=i||k>=i) continue;
				if(i-j>w||i-k>w) continue;
				dp[i][j][k] = max(max(max(dp[i-1][j-1][k-1], dp[i-1][j][k-1]), dp[i-1][j-1][k]), dp[i-1][j][k]);
				dp[i][j][k] += a[j][i-j] + a[k][i-k];
				if(j==k) dp[i][j][k]-=a[j][i-j];
			}
		}
	}
	cout << dp[h+w][h][h] << '\n';
}
