#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define int ll
#define vi vector<int>
#define vb vector<bool>
#define vvb vector<vb >
#define pii pair<int,int>
#define ss second
#define ff first
#define vpii vector<pii>
#define vvi vector<vi >
#define vs vector<string>
#define vvs vector<vs >
#define pqi priority_queue <int>
#define minpqi priority_queue <int, vector<int>, greater<int> >
#define all(x) x.begin(),x.end()
#define mii map<int,int>
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define per1(i,n) for(ll i=n;i>0;i--)
#define repeat(i,start,n) for(ll i=start;i<n;i++)
#define inp(arr,n) ll arr[n];rep(i,n){ cin>>arr[i];}
#define inp1(arr,n) ll arr[n+1];rep1(i,n){ cin>>arr[i];}
#define inp2d(arr,n,m) ll arr[n][m];rep(i,n)rep(j,m)cin>>arr[i][j];
#define inpg(adj,m) rep(i,m){int a,b;cin>>a>>b;adj[a].pb(b);adj[b].pb(a);}
#define print(a,n) for(ll i=0;i<n;i++){ cout<<a[i]<<" ";}
#define print1(a,n) for(ll i=1;i<=n;i++){ cout<<a[i]<<endl;}
#define mod 1000000007
#define maxx 1000000000000000000
#define PI 3.141592653589793238462643383279
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define init(arr,a) memset(arr,a,sizeof(arr))
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element

/*freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);*/
//------------------------------------Code Starts here------------------------------------//

void solve()
{

}
main()
{
	int n;
	cin>>n;
	int a[n];
	for0(i,n)cin>>a[i];
	 int pre[n+1];
	pre[0]=0;
	for1(i,n)
	{
		a[i-1]%=mod;
		pre[i]=(pre[i-1]%mod+a[i-1]%mod)%mod;
		pre[i]%=mod;
	}
	 int sum=0;
	for0(i,n)
	{
		sum=(sum%mod+((a[i]%mod)*((pre[n]-pre[i+1]+mod)%mod))%mod)%mod;
		sum%=mod;
	}
	cout<<sum%mod;
}
