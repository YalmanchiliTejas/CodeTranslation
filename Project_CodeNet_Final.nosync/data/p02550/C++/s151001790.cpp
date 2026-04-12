#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define floop(i,a,n) for (int i=a;i<n;i++)
#define rfloop(i,a,n) for (int i=n-1;i>=a;i--)
#define mloop(it,x) for(it=x.begin();it!=x.end();it++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((ll)(x).size())
#define cases ll t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef unsigned long long int ull;
typedef vector<ll> vec;
typedef pair<ll,ll> pll;
typedef double db;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll mod=1000000007;
ll pm(ll x,ll n) {ll result=1; while(n>0){if(n%2==1) result=((result%mod)*(x%mod))%mod; x=((x%mod)*(x%mod))%mod; n/=2;} return result;}
ll p(ll x,ll n) {ll result=1; while(n>0){if(n%2==1) result=result*x; x=x*x; n/=2;} return result;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll ncr(ll n,ll r) { ll p=1,k=1; if(n-r<r) r=n-r; if(r!=0) {while(r!=0) {p*=n; k*=r; ll temp=gcd(p,k); p/=temp; k/=temp; n--; r--;} } else p=1; return p;}
ll factorial[300000+1];
void fact(ll n) { factorial[0]=1; factorial[1]=1; floop(i,2,n+1) factorial[i] = (i * factorial[i-1]%mod) % mod; }
ll d,coeff1,coeff2; 
void euclid(ll a, ll b) { if(b==0) { d=a; coeff1=1; coeff2=0; } else { euclid(b,a%b); ll temp=coeff1; coeff1=coeff2; coeff2=temp-(a/b)*(coeff2); } }
ll modinv(ll a) { euclid(a,mod); return (coeff1%mod+mod)%mod; }
int prime[1000001]={};
int spf[1000001]={};
void sieve(ll n)
{
	prime[0]=1;
	prime[1]=1;
	for(ll i=2;i*i<=n;i++)
	{
		if(prime[i]==0)
		{
			for(ll j=i*i;j<=n;j+=i)
			{
				prime[j]=1;	
				if(spf[j]==j)
				spf[j]=i;	
			}		
		}
	}
}
/*
vec s(300000,0);
vec si(300000,1);
ll root(ll a)
{
	while(s[a]!=a)
	a=s[a];
	return a;
}
void uni(ll a,ll b)
{
	ll r1=root(a);
	ll r2=root(b);
	if(si[r1]<si[r2])
	{
		s[r1]=s[r2];
		si[r2]+=si[r1];
	}
	else
	{
		s[r2]=s[r1];
		si[r1]+=si[r2];
	}
}
vector<vec > adj(300000);
vec vis(300000,0);
vec dist(300000,0);
void dfs(ll t,ll n)
{
	vis[t]=1;
	floop(i,0,sz(adj[t]))
	{
		if(vis[adj[t][i]]==0)
		{
			dist[adj[t][i]]=dist[t]+1;
			vis[adj[t][i]]=1;
		//	sum[adj[t][i]]=sum[t]+c[t][adj[t][i]];
			dfs(adj[t][i],n);
		}
	}
}*/
struct my_comp
{
	bool operator()(pair<ll,pll> p1, pair<ll,pll> p2)
	{
		if(p1.fi!=p2.fi)
		return p1.fi>p2.fi;
		return p1.se.fi<p2.se.fi;
	}
};
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);	

int main()
{
	ll n,x,m;
	cin>>n>>x>>m;
	map<ll,ll> done;
	vector<ll> wow;
	mod=m;
	ll te=-1;
	ll pos=-1;
	ll ans=0;
	floop(i,1,n+1)
	{
		ll temp=(x%m+m)%m;
		//cout<<temp<<" ";
		if(temp==0)
		break;
		if(done.count(temp))
		{
			te=temp;
			pos=i;
			break;
		}
		ans+=temp;
		done[temp]=i;
		wow.pb(temp);
		x=temp*temp;
	//	cout<<ans<<" ";
	}
	if(pos!=-1)
	{
		//cout<<(n-pos)/(pos-done[te])<<" ";
		
		ll mo=(n-pos+1)%(pos-done[te]);
		//cout<<ans<<" ";
		ll yo=0;
		floop(i,done[te]-1,mo+done[te]-1)
		ans+=wow[i];
		ll s=0;
		floop(i,done[te]-1,pos)
		s+=wow[i];
		ans+=((n-pos+1)/(pos-done[te]))*s;
	}
	cout<<ans<<"\n";	
	return 0;
}