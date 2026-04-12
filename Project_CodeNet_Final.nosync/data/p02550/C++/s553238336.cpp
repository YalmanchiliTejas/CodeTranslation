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
#define bits(x) __builtin_popcountll(x)
#define minimum(a,n) min_element(a,a+n)-a
#define maximum(a,n) max_element(a,a+n)-a
#define pqbig priority_queue<int>
#define pqsmall priority_queue<pii,vector<pii>,greater<pii> >
#define all(v) v.begin(),v.end()
#define sitr set<int>:: iterator
#define spitr set<pii>:: iterator
#define mitr map<int,int>:: iterator

int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring ( int number ) {stringstream ss; ss << number; return ss.str();}


typedef tree<pii, null_type, less<pii>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;


#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

const int N=1e5+5;
int dp[N];

int32_t main()
{
	fast;
	int n,x,m;cin>>n>>x>>m;
	dp[1]=x;
	mii exist;
	exist[x]=1;
	int last=x;
	int id=-1;
	int i=2;

	while(true)
	{
		int num=(last*last)%m;

		//trace1(num);

		if(exist.count(num))
		{
			id=exist[num];
			break;
		}

		exist[num]=i;
		dp[i]=num;
		last=num;
		i++;
	}

	for(int j=1;j<i;j++)
		dp[j]+=dp[j-1];


	int len=i-id;

	if(n<i)
	{
		cout<<dp[n]<<endl;
		return 0;
	}

	int rep_sum=dp[i-1]-dp[id-1];

	n-=(i-1);
	int ans=dp[i-1];
	int val=n/len;
	ans+=rep_sum*val;
	n-=val*len;

	ans+=dp[id+n-1]-dp[id-1];

	cout<<ans<<endl;
}
