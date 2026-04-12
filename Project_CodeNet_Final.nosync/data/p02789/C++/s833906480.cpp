#include <bits/stdc++.h>
     //https://www.codechef.com/viewsolution/28454497
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define vi vector<int>
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<endl
#define mod 1000000007
#define int long long
vector < ll> primes;
 int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
bool isvalid(int x,int y){
  return (x>=0 and x<n and y>=0 and y<m);
}
void Sieve(ll n) 
{ 
    bool prime[n+1];
	for(ll i=0;i<n+1;++i)
		prime[i]=true;
    for (ll p=2;p*p<=n;++p) 
    {
        if (prime[p] == true) 
        {  
            for (ll i=2*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }  
    for(ll p=2; p<=n; p++) 
       if (prime[p]) 
		primes.push_back(p);  
}
 const int N = 5e5 + 5;
 	int connected;
	int par[N], sz[N];
 
struct DSU
{

	void init(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		connected=n;
	}
 
	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}
 
	int getSize(int k)
	{
		return sz[getPar(k)];
	}
 
	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);
 
		if(par1==par2)
			return;
 
		connected--;
 
		if(sz[par1]>sz[par2])
			swap(par1, par2);
 
		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};
 
 

DSU dsu;
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
        return gcd(b % a, a); 
} 
ll powermod(ll x, ll y){
    if(y==0)
    return 1;
        
    if(y%2==0)
    return (powermod(x,y/2)*powermod(x,y/2))%mod;
    else
    return (((powermod(x,y/2)*powermod(x,y/2))%mod)*x)%mod;
}
   
int32_t main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n,m;
    cin>>n>>m;
    if(n==m)cout<<"Yes";
    else cout<<"No";
    
    
    
    
}

