
// Problem : E - Sequence Sum
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*

WINNERS NEVER QUIT AND QUITTERS NEVER WIN!!

Falling down is an accident, Staying down is a choice.

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef vector<long> vl;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;

#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define REV(i,a,b) for(long long i=a;i>=b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define tc ll tests;cin>>tests;while(tests--)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define coutv(v) for(auto it: (v))cout<<it<<" ";newl;
#define cout2d(v) for(auto it: (v)) {for(auto j:it) cout<<j<<" ";newl;}
#define cinv(v,n) vll (v)(n);FOR(i,0,(n)){cin>>v[i];}
#define cinvg(v,n) (v).resize(n);FOR(i,0,(n)){cin>>v[i];}
#define cin2d(v,n,m) vvll (v)(n,vll(m,0));FOR(i,0,n){FOR(j,0,m){cin>>v[i][j];}}
#define cin2dg(v,n,m) (v).resize(n,vll(m));FOR(i,0,n){FOR(j,0,m){cin>>v[i][j];}}
#define newl cout<<"\n"
#define mod 1000000007
#define INF LLONG_MAX/2

int main()
{
    io;
    
    ll n,x,m,ans=0;
    cin>>n>>x>>m;
    
    vb vis(m+1);
    vll a;
    
    ll p=x*x;
    while(!vis[p%m])
    {
    	a.pb(p%m);
    	vis[p%m]=true;
    	p=p%m;
    	p*=p;
    }
    
    ll j=0;
    FOR(i,0,a.size())
    {
    	if(a[i]==p%m)
    	{
    		j=i;//cycle start end at j
    		break;
    	}
    }
    
    ans+=x;
    n--;
    FOR(i,0,min(n,j))
    {
    	ans+=a[i];
    	n--;
    }
    //cout<<n;newl;
    ll cycle=0;
    FOR(i,j,a.size())
    {
    	cycle+=a[i];
    }
    ll sz=(ll)a.size()-j; //size of cycle 
    
    ans+=cycle*(n/sz);
    n=n%sz;
    FOR(i,j,j+n)
    {
    	ans+=a[i];
    }
    
    cout<<ans;
    
    return 0;
}

