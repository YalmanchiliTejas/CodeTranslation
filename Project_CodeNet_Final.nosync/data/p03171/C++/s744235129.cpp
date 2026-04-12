#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define vi vector <int>
#define endl "\n"
#define f(n) for(int i=0;i<n;i++)
#define vvi vector <vector<int> >
#define vii vector <pair<int,int> >
#define rep(i,a,b) for (int i=a;i<b;i++)
#define repD(i,a,b) for (int i=a;i>=b;i--)
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gcd __gcd
#define init(i,k) memset(i,k,sizeof i)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define setBits(x) __builtin_popcountll(x)
#define pii pair <int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define N 100005
#define mod 1000000007
int dp[3001][3001];
vi v(N);
int fun(int i,int j,int n)
{
	if(i>j)
	{
		return 0;
	}
	int r=i+n-1-j;
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if(r%2==0)
	{
		dp[i][j]=max((v[i]+fun(i+1,j,n)),(v[j]+fun(i,j-1,n)));
	}
	else
	{
		dp[i][j]=min(fun(i+1,j,n),fun(i,j-1,n));
	}
	return dp[i][j];
}
void solve()
{
	int n;
	cin>>n;
	int sum=0;
	f(n)
	{
		cin>>v[i];
		sum+=v[i];
	}
	int x=fun(0,n-1,n-1);
	int y=sum-x;
	cout<<y-x<<endl;
	return ;

}

signed main()
{
    int t=1;
    //cin>>t;
    for(int i=0;i<3001;i++)
    {
    	for(int j=0;j<3001;j++)
    	{
    		dp[i][j]=-1;
    	}
    }
    for(int i=1;i<=t;i++)
    {
    	//cout<<"Case #"<<i<<": ";
    	solve();
    	//cout<<endl;
    }
    return 0;
}