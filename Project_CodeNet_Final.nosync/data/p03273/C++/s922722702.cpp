#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define db long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound 
#define pii pair<int , int>
#define pdd pair<double , double>
#define pll pair<long long int,long long int>
#define vpl vector<pll >
#define vll vector<ll >
#define mod 1000000007
#define inf 1000000000000000007
#define eps 0.000001
#define stp setprecision(20)
#define endl '\n'
int main()
{  
    fastio;
    /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    */
    ll n,m;cin>>n>>m;
    char a[n][m];
    for(ll i=0;i<n;i++)
    	for(ll j=0;j<m;j++)
    		cin>>a[i][j];
    for(ll i=0;i<n;i++)
    {
    	bool bb=0;
    	for(ll j=0;j<m;j++)
    		if(a[i][j]=='#')
    			bb=1;
    	if(!bb)
    	{
    		for(ll j=0;j<m;j++)
    			a[i][j]='*';
    	}
    }
    for(ll j=0;j<m;j++)
    {
    	bool bb=0;
    	for(ll i=0;i<n;i++)
    		if(a[i][j]=='#')
    			bb=1;
    	if(!bb)
    	{
    		for(ll i=0;i<n;i++)
    			a[i][j]='*';
    	}
    }
    vector<char > v[n];
    for(ll i=0;i<n;i++)
    {
    	for(ll j=0;j<m;j++)
    		if(a[i][j]!='*')
    			v[i].pb(a[i][j]);
    }
    for(ll i=0;i<n;i++)
    {
    	if(v[i].size()==0)
    		continue;
    	for(ll j=0;j<v[i].size();j++)
    		cout<<v[i][j];
    	cout<<endl;
    }
} 

