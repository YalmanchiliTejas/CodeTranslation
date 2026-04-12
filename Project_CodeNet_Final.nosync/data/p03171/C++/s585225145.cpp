#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl '\n'
#define maxl __LONG_LONG_MAX__
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define rep(i, n) for(int i = 0; i < n; i++)
#define rev(i, n) for(int i = n-1; i >= 0; i--)
#define rep1(i, n) for(int i=1; i < n; i++)
#define rev1(i, n) for(int i=n ; i > 0; i--)
#define FOR(i, a, b) for(int i=a ; i < b; i++)
#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define n_ones(x) __builtin_popcountll(x)
#define n_trailzero(x) __builtin_ctzll(x)
#define n_leadingzero(x) __builtin_clz(x)
#define sz(a) (ll)(a.size())

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<ll>> vvll;
typedef stack<ll> stk;
typedef queue<ll> que;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_setll;
typedef tree<char,null_type,less<char>,rb_tree_tag,
tree_order_statistics_node_update> indexed_setc;

ll max(int a,ll b){ return max((ll)a,b);}
ll min(int a,ll b){ return min((ll)a,b);} 
ll min(ll a,int b){ return min(a,(ll)b);}
ll max(ll a,int b){ return max(a,(ll)b);}

ll mod = 1e9 + 7;

void solve()
{
	ll n;
	cin>>n;
	ll a[n];
	rep(i, n)
		cin>>a[i];
	ll dp[n][n] = {0};
	//dp[i][j] -> value of X - Y when left and right pointers are at i and j
	for(ll i = n-1 ; i >= 0; i--)
	{
		for(ll j = i; j < n; j++)
		{
			if(i == j)
				dp[i][j] = a[i];
			else
				dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
		}	
	} 
	cout<<dp[0][n-1]<<endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
	ll t = 1;
	//cin>>t;
	rep(i, t)
		solve();
	return 0;
	
}