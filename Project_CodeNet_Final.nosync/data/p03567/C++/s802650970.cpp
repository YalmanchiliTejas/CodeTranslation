#include <bits/stdc++.h>
#define ll long long int
#define ff first
#define pb push_back
#define ss second
#define debug 0
#define ff first
#define mp make_pair
 
using namespace std;
 
const ll MOD = 1000000007LL;
 
ll fact[1000006];
ll ifact[1000006];
ll power2[1000006];
 
ll ar[2000056];
ll visit[2000056];
ll least_prime[1000005];
ll level[300005];
vector<int> adj[5000005];

const long double pi=3.1415926535897;

set<string> st;
 
bool vis[500020];
 
bool prime[10000006];
 
vector<int> primes,pec,vec;

vector<pair<ll,ll> > vp;

map<ll,ll> has;


ll day[3000006];
 
 
 
ll powr (ll a, ll  b)
{
    if (b == 0)
        return 1;
    long long int x = powr(a, b/2);
    if (b % 2 == 0)
        return (x*x)%MOD;
    else
        return ((x*x)%MOD*a%MOD)%MOD;
}
 
inline ll inv(ll x) {
  return powr(x, MOD - 2);
}
 
inline ll mulMod(ll a, ll b) {
  return (a%MOD * b%MOD) % MOD;
 
}
 
inline void process() {
  fact[0] = 1;
  power2[0] = 1;
  for(int i = 1; i < 200003; i++) {
    fact[i] = mulMod(fact[i - 1], i);
    power2[i] = mulMod(power2[i - 1], 2);
  }
  ifact[200002] = inv(fact[200002]);
  for(int i = 200002 - 1; i >= 0; i--) {
    ifact[i] = mulMod(ifact[i + 1], i + 1);
  }
}
 
inline ll ncr(ll n, ll r) {
  if(n < r) return 0;
  return mulMod(fact[n], mulMod(ifact[r], ifact[(n - r)]));
}
 
 
 
void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    
    for(ll i=2;i*i<=1000006;i++)
    {
        if(prime[i])
        {
            for(ll j=i*2;j<=1000006;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    
    for(int i=2;i<=100005;i++)
    {
    	if(prime[i])
    	primes.pb(i);
	}
}





void LeastPrimeFactor(){
	int tot=1000003;
	least_prime[1]=1;
	for (ll i = 2; i <tot; i += 2)	least_prime[i] = 2;
	for (ll i = 3; i < tot; i += 2){
		if (!visit[i]){
			least_prime[i] = i;
			for (ll j = i; (j*i) < tot; j += 2){
				if (!visit[j*i])
				{
					visit[j*i] = true;
					least_prime[j*i] = i;
				}
			}
		}
	}
}

ll solve(ll n, ll k)
{
    ll res = 1;
  
    
    if (k > n - k)
        k = n - k;
  
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res%=MOD;
        ll p =inv(i+1);
        res=(res%MOD*p%MOD)%MOD;
    }
    
    return res;
  
}
  
ll catalan(ll n)
{
   
    ll c = solve(2*n, n);
    ll d= inv(n+1);
    ll ans = (c%MOD*d%MOD)%MOD;
    return ans;
}




 

int main() 
{
//	freopen("input4.in","r",stdin);
//	freopen("output4.out","w",stdout);
    ll n,m,t,p,q,s,c,d,e,f,g,h,res=0,u,v,i,j,l=0,k,len,tot=0,rad,w,pos=0,y,r=0,z,x,maxm=-1;
	ll cycle,val,max1=0,max2=0,num=0,zero,ans=0,min1=INT_MAX,min2=INT_MAX,sum=0;
    bool flag=0;
    ll a,b,minm=INT_MAX;
    ll x1,x2;
    
    string str;
    
   cin>>str;
   
   len=str.length();
   
   
   for(i=0;i<len-1;i++)
   {
   	 if(str[i]=='A' && str[i+1]=='C')
   	 {
   	 	flag=1;
   	 	break;
		}
   }
    
    if(flag)
    cout<<"Yes";
    else
    cout<<"No";
   
	
    
	return 0;
    
}    