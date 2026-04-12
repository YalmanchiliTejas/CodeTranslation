#include<bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long int
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define loope(i,a,b) for(ll i=a;i<=b;++i)
#define loopr(i,a,b) for(ll i=a;i>=b;--i)
#define loops(i,a,b,step) for(ll i=a;i<b;i+=step)
#define all(a) a.begin(),a.end()
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define V vector
using namespace std;
typedef string str;
ll vis[55][55]={0};
ll inp[55][55];
set<pair<ll,ll>> points,point;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;     
  
    x = x % p;   
    while (y) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;  
        x = (x*x) % p; 
    } 
    return res; 
} 
 
ll nCrModP(ll n, ll r, ll p) 
{ 
    if (!r) 
      return 1; 
  
	ll fac[n+1]; 
   	fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* power(fac[r], p-2,p) % p * power(fac[n-r], p-2,p) % p) % p; 
}
void dfs(ll x,ll y,ll k,ll n)
{
    if (x<0 || y<0 || x>n-1 || y>n-1 || inp[x][y]==1 || vis[x][y]==k)
    {
        return ;
    }
    else
    {
        vis[x][y]=k;
        if (k==1)
        {
            points.insert(make_pair(x,y));
        }
        else
        {
            point.insert(make_pair(x,y));            
        }
        dfs(x-1,y,k,n);
        dfs(x,y-1,k,n);
        dfs(x+1,y,k,n);
        dfs(x,y+1,k,n);
    }
    
}
int main ()
{
	FAST;
	//test cases
	ll t;
    cin>>t;
    V<ll>v(t);
    ll ans=0;
    ll num=1000000007;
    loop(i,0,t)
    {
        cin>>v[i];
        ans+=v[i];
    }
    ans%=num;
    ans=ans*ans;
    ans%=num;
    loop(i,0,t)
    {
        ans%=num;
        ll tem=((v[i]*v[i])%num);
        ans-=tem;
        if (ans<0)
        {
            ans+=num;
        }
    }
    ll num2=1000000008/2;
    ans=(ans*num2)%num;
    cout<<ans<<endl;
}   