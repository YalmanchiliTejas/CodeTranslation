/*
        |___Arshit Mangukiya___|
        |___DA-IICT____|
        |___201801173____|
*/
        //__WRITE  YOUR  CODE  HERE___//
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;            
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppl;
typedef vector<pll> vpl;
#define ff first
#define ss second
#define pi acos(-1)
#define mr_ad_0501 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
#define all(a)      a.begin(),a.end()
#define f(i,a,n) for(ll i=a;i<n;i++)
#define MOD 1000000007
#define MAX 200007
#define LM LLONG_MAX
#define sz size()
#define p(x)        cout<< x << " ";
#define pe(x)       cout<< x << endl ;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
const int N=1e5+5;
        /*  bool fun(pair<int,int>a , pair<int,int>b)
            {
                if(a.ff == b.ff)    return a.ss < b.ss;
                else            return a.ff < b.ff;
            }*/
 /*void bfs(ll x)
 {
    queue<ll> q;
    q.push(x);
    while(!q.empty())
    {
        ll k=q.front();
        q.pop();
        for(auto X:v[k])
        {
            if(!vis[X])
            {
                l[X]=l[k]+1;
                vis[X]=1;
                q.push(X);
            }
        }
    }
 }*/
//ll i,j;
/*void dfs(ll v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}*/

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll mod_pow(ll a,ll b,ll m)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
        	res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}
 
ll mod_inverse(ll a)
{
	return mod_pow(a , MOD-2 , MOD);
}

void solve()
{
	ll n;
	cin>>n;
	if(n>=30)cout<<"Yes";
	else cout<<"No";
}
    
int32_t main(){
    mr_ad_0501;
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    
}    	