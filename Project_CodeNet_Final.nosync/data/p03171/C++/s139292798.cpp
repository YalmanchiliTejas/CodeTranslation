#include<bits/stdc++.h>
#define int long long int  //comment for large arrays
#define pll pair<int,int>
#define dbl long double
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define eps 0.00000001
#define INF 10000000000000001
#define all(x) (x).begin(),(x).end()
#define LB(v,x) (lower_bound(all(v),x) - v.begin()) 
#define UB(v,x) (upper_bound(all(v),x) - v.begin())
#define size(x) (int)(x).size()
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define popb() pop_back()
#define popf() pop_front()
#define mp(x,y) make_pair((x),(y))
#define vec(dt) vector<dt>
#define vv(dt) vector<vector<dt>>
#define fastio(x) ios_base::sync_with_stdio(x); cin.tie(NULL)
#define init(v,s) memset(v,s,sizeof(v)) 
#define bug(x) cerr<<"LINE: "<<__LINE__<<" || click to see test details "<<#x<<" = "<<x<<endl
#define loop(i,s,n) for(int i=s;i<n;i++)
#define print(v) for(auto it:v) cout<<it<<" "; cout<<endl 
using namespace std;


signed main()
{
	fastio(0);
	int n;
	cin>>n;
	int a[n+1],dp[n+1][n+1];
	loop(i,1,n+1) 
	{
		cin>>a[i];
		dp[i][i] = a[i];
	}
	for(int i=n;i>0;i--)
		for(int j=i+1;j<=n;j++)
			dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
	cout<<dp[1][n]<<endl;
	return 0;		
}