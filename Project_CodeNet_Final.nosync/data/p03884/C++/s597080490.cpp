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

const ll INF = ll(2e18);
const int C = 550;
string s = "FESTIVA";

ll dp[C+1][7];
ll cnt[C+1];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x; cin>>x;
	for(int i = 0; i < 7; i++) dp[1][i] = 1;
	for(int i = 2; i <= C; i++)
	{
		dp[i][0] = i;
		for(int j = 1; j < 7; j++)
		{
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
			if(dp[i][j]>=INF) dp[i][j]=INF;
		}
	}
	ll ext = 5000 - C*7;
	for(int i = C; i >= 1; i--)
	{
		ll r = x/dp[i][6];
		ext-=r;
		cnt[i] = r;
		x -= r*dp[i][6];
	}
	for(int i = 1; i <= C; i++)
	{
		cout<<s;
		for(int j = 0; j < cnt[i]; j++)
		{
			cout<<"L";
		}
	}
	cout<<'\n';
}
