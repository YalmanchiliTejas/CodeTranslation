#include<bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define int         ll int
#define float       double
#define	endl		'\n'
#define maxpq       priority_queue<ll>
#define minpq       priority_queue<ll, vector<ll>, greater<ll> >
#define mii         map<int,int>
#define msi         map<string,int>
#define mis         map< int, string>
#define mpi         map<pair< int, int>, int>
#define pii         pair< int, int>
#define vi          vector< int>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define EPS         1e-9
#define INF         1e18
#define PI          3.14159265358979323846
#define MAXI        1000000
#define what_is(x)  cerr << #x << " is " << x << endl;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
#define N 100005
int dp[3005][3005];
int rec(int arr[],int n,int start,int end)
{
	if(start>end) return 0;
	if(start==end) return arr[start];
	if(start==end-1) return max(arr[start],arr[end]);
	if(dp[start][end]!=-1) return dp[start][end];
	return dp[start][end]=max(arr[start]+min(rec(arr,n,start+2,end),rec(arr,n,start+1,end-1)),arr[end]+min(rec(arr,n,start+1,end-1),rec(arr,n,start,end-2)));// dusre player ka intension reduce karna hoga
	
}
signed main()
{
	fast;
	int t=1;
	//cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		int i,j,k;
		int sum=0;
		for(i=0;i<=n-1;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		memset(dp,-1,sizeof(dp));
		int ans=rec(arr,n,0,n-1);
		cout<<ans-(sum-ans)<<endl;
	}
}