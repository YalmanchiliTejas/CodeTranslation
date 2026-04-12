#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 1000000007LL
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(i=a;i<=b;i++)

#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

ll mypow(ll a, ll b) { if(b == 0) return 1; ll temp=mypow(a,b/2); temp=(temp*temp)%INF; if(b%2 == 1) temp=(a*temp)%INF; return temp; }
int mygcd(int a, int b) { if(b==0) return a; return mygcd(b,a%b); }
int cntBits(ll a) { int ret=0; while(a>0) { ret++; a/=2; } return ret; }

ll arr[3030];
pll dp[3003][3003][2];

void func(int l, int r, int turn)
{
	if(dp[l][r][turn].ff!=-1 && dp[l][r][turn].ss!=-1) return;
	dp[l][r][turn].ff=dp[l][r][turn].ss=0;
	if(l==r)
	{
		if(turn==0) dp[l][r][turn].ff=arr[l];
		else dp[l][r][turn].ss=arr[l];
		return;
	}
	func(l+1, r, 1-turn);
	func(l, r-1, 1-turn);
	if(turn==0)
	{
		pll temp1=dp[l+1][r][1-turn];
		temp1.ff+=arr[l];
		pll temp2=dp[l][r-1][1-turn];
		temp2.ff+=arr[r];
		if(temp1.ff-temp1.ss > temp2.ff-temp2.ss) dp[l][r][turn]=temp1;
		else dp[l][r][turn]=temp2;
	}
	else
	{
		pll temp1=dp[l+1][r][1-turn];
		temp1.ss+=arr[l];
		pll temp2=dp[l][r-1][1-turn];
		temp2.ss+=arr[r];
		if(temp1.ff-temp1.ss > temp2.ff-temp2.ss) dp[l][r][turn]=temp2;
		else dp[l][r][turn]=temp1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int tt=1,tcase; 
	//cin >> tt;
	rep(tcase,1,tt)
	{
		int n; cin >> n;
		for(int i=0;i<n;i++) cin >> arr[i];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<2;k++)
				{
					dp[i][j][k].ff=dp[i][j][k].ss=-1;
				}
			}
		}
		func(0,n-1,0);
		cout << dp[0][n-1][0].ff-dp[0][n-1][0].ss << "\n";
	}
	return 0;
}
