#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void sb()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
vector<vector<ll>> dp;
vector<ll> v;
ll solve(int i,int j){
	if(i>j)
		return 0ll;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i==j)
		return dp[i][j] = v[i];

	dp[i][j] = max(v[i]-solve(i+1,j),v[j]-solve(i,j-1));

	return dp[i][j];

}
int main()
{
	
	ll n;
	cin>>n;
	 v =  vector<ll>(n);
	dp = vector<vector<ll>>(n+1,vector<ll>(n+1,-1));
	for(int i=0;i<n;i++)
		cin>>v[i];

	cout<<solve(0,n-1)<<endl;
	
}