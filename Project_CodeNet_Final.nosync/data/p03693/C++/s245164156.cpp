#include<bits/stdc++.h>
// #include <boost/lexical_cast.hpp>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define vllv vector<vector<ll>> 
#define vpii vector<pair<ll,ll>>
#define pll  pair<ll,ll>
#define sz size()
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1000000000+7;
ll ceil1(ll n,ll m){if(n%m==0){return n/m;}return n/m +1;}
ll factor(ll n){
    vll ans;
	if(n==2)ans.pb(2);
	else
    {for(ll i=2;i*i<=n;i++){if(n%i==0 && n%i!=i){ans.pb(i);if(n/i!=i)ans.pb(n/i);}}ans.pb(n);}
    return ans.sz+1;
}
ll fact(ll n){ll res = 1;for (ll i = 2; i <= n; i++)res = res * i; 
    return res; } 
  
ll nCr(ll n, ll r){ return fact(n) / (fact(r) * fact(n - r)); } 
  
void dfs(vllv &v,ll k,vll &par,vll &dis,ll p)
{
    par[k]=p;
    dis[k]=dis[p]+1;
    for(ll i=0;i<v[k].sz;i++){
        if(v[k][i]!=p){
            dfs(v,v[k][i],par,dis,k);
        }
    }
}
bool sortbysec(const pair<string,int> &a,const pair<string,int> &b){return (a.second<b.second);} 

ll pow2(ll n,ll k){ll ans=1;
    while(k>0){
        if(k%2==1)ans=ans*n;n=n*n;k/=2;
    }return ans;}
bool prime(int n){
    int i,j;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void solve()
{
	int r,g,b;
	cin>>r>>g>>b;
	int x=r*100+g*10+b;
	// cout<<x;
	if(x%4==0)
		cout<<"YES";
	else
		cout<<"NO";
	return;
}            
int main()
{
	fast;
    ll q;
    q=1;
    // cin>>q;
    while(q--)
    {
        solve();
    }
    return 0;
}
