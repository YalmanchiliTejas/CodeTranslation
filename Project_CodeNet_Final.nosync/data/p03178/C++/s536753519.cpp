#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[11111][111][2];
vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s; s="0"+s; int d; cin>>d;
	int n=s.length();
	dp[0][0][0]=1;
	for(int i=0;i+1<n;i++)
	{
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<2;k++)
			{
				int v=dp[i][j][k];
				if(v==0) continue;
				for(int dig=0;dig<10;dig++)
				{
					if(!k&&(dig>s[i+1]-'0')) continue;
					int newk=k;
					if(!k&&(dig<s[i+1]-'0')) newk=1;
					dp[i+1][(j+dig)%d][newk]=add(dp[i+1][(j+dig)%d][newk],v);
				}
			}
		}
	}
	int ans = MOD-1;
	for(int k=0;k<2;k++)
	{
		ans=add(ans,dp[n-1][0][k]);
	}
	cout<<ans<<'\n';
}
