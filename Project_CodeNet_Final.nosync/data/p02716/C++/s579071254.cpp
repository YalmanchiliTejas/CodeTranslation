#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;


#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PSET(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define pii pair<int,int>
#define pf push_front
#define mp make_pair
#define vi vector<int>
#define vip vector<pair<int,int> >
#define ff first
#define ss second
#define int long long
#define mod 1000000007
#define BIG 998244353
#define s(t) scanf("%lld",&t)
#define p(t) printf("%lld\n",t)
#define mii map<int,int>
#define MSET(table,i) memset(table, i, sizeof(table))
#define endl '\n'
#define tc int t;cin>>t;while(t--)
#define pi  3.1415926358
#define bits(x) __builtin_popcount(x)
#define minimum(a,n) min_element(a,a+n)-a
#define maximum(a,n) max_element(a,a+n)-a
#define pqbig priority_queue<pii>
#define pqsmall priority_queue<int,vector<int>,greater<int> >
#define all(v) v.begin(),v.end()
#define sitr set<int>:: iterator
#define spitr set<pii>:: iterator
#define mitr map<int,int>:: iterator

int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring ( int number ) {stringstream ss; ss << number; return ss.str();}


typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;


#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

const int N=2e5+5;
int dp[N][10],arr[N];
int n;

int solve(int id,int left,int kitne)
{
	//trace3(id,left,kitne);
	if(kitne==0)
		return 0;

	if(dp[id][left]!=-1)
		return dp[id][left];

	int ans=-1e18;

	if(left)
		ans=max(ans,solve(id+1,left-1,kitne));

	int cur=arr[id];
	for(int i=id+2;i<=id+2+left;i++)
		ans=max(ans,cur+solve(i,left-(i-(id+2)),kitne-1));
	return dp[id][left]=ans;
}

int32_t main() 
{
    fast;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>arr[i];
    MSET(dp,-1);

    if(n%2==0)
   		cout<<solve(1,1,n/2);
    else
    	cout<<solve(1,2,n/2);
}