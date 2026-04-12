/*input
98765432109876543210
58
*/
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize ("unroll-loops")*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define input(str) freopen(str,"r",stdin);
#define output(str) freopen(str,"w",stdout);
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF  3e16+1
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld\n",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define modd 1000000007
#define len(x) x.size()
#define all(v) (v.begin(),v.end())
#define ll int
#define pi 3.1415926535897932384626
#define ld double
const int N =2e5+2;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
int n,d;
string k;
int dp[10005][100][2];
int recur(int pos,int sum,int flag)
{
	if(pos==n)
	{
		int some=(sum)%d;
		if((some)>0)
			return 0;
		else
		{
			return 1;
		}
	}
	else if(dp[pos][sum][flag]!=-1)
		return dp[pos][sum][flag];
	else
	{
		int tmp=0;
		int temp=k[pos]-'0';
		for(int i=0;i<temp;i++)
		{
			int some=(sum+i)%d;
			tmp+=recur(pos+1,some,0);
			tmp%=modd;
		}
		if(flag)
		{
			int some=(sum+temp)%d;
			tmp+=recur(pos+1,some,1);
			tmp%=modd;
		}
		else
		{
			for(int i=temp;i<10;i++)
			{
				int some=(sum+i)%d;
				tmp+=recur(pos+1,some,0);
				tmp%=modd;
			}	
		}
		dp[pos][sum][flag]=tmp;
		return dp[pos][sum][flag];
	}
}
signed main()
{
	speed
	cin>>k;
	cin>>d;
	n=len(k);
	//cout<<n<<endl;
	rep(i,10005)
	{
		rep(j,100)
		{
			rep(h,2)
			{
				dp[i][j][h]=-1;
			}
		}
	}
	int ans=-1;
	int val=k[0]-'0';
	for(int i=0;i<val;i++)
	{
		ans+=recur(1,i,0);
		ans%=modd;
	}	
	ans+=recur(1,val,1);
	ans%=modd;
	cout<<ans<<endl;
	return 0;
}