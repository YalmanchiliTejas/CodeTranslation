#include<bits/stdc++.h>
using namespace std;


#define flush  cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define acc (ios::sync_with_stdio(false),cin.tie(0))

#define fill(w,t) memset(w,t,sizeof(w))

#define bl '\n'
#define nl cout<<bl
#define cout1(a) cout<<a<<bl
#define cout2(a,b) cout<<a<<" "<<b<<bl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<bl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<bl
#define print(a,s,e) for(ll i=s;i<=e;i++){ cout<<a[i]<<" "; }
#define rprint(a,s,e) for(ll i=s;i>=e;i--){ cout<<a[i]<<" "; }
#define input(a,s,e) sfor(p,s,e) cin>>a[p]

#define all(v) v.begin(),v.end()

#define ll long long
#define ldb long double
#define db double
#define ull unsigned long long

#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair

#define pll pair<ll,ll>

#define pldb pair<ldb,ldb>

#define vull vector<ull>
#define vll vector<ll>
#define vldb vector<ldb>
#define vpll vector< pll >
#define vpldb vector< pldb >

#define pqmin priority_queue<ll,vector<ll>,greater<ll> >
#define pq priority_queue<ll>
#define pqpll priority_queue<pll>
#define pqpllmin priority_queue<pll, vector<pll>, greater<pll> >


#define mll map<ll,ll>
#define mldb map<ldb,ldb>
#define umll unordered_map<ll,ll>

#define sfor(i,a,b) for (ll i = (a); i <= (b); ++i)
#define rfor(i,b,a) for (ll i = (b); i >= (a); --i)

const ll mod = 1e9+7;
const ll maxn = 1e6+1;
#define llmax LLONG_MAX
#define llmin LLONG_MIN
const ldb PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899863;

ll *fact , *ifact;
vll primes;
ll *spf; 
void sieve() 
{
    spf = new ll[maxn+1];
    fill(spf,0);
	spf[0]=0; spf[1]=1;
    for(ll i =2; i<=maxn; i++)
    {
        if(spf[i])
         continue;
        spf[i]=i;
        for(ll j = i*i; j<=maxn; j+=i)
        {
        	if(spf[j]==0)
         	    spf[j]=i;
    	}
    }
    for (ll p=2; p<=maxn; p++)
      if (spf[p]==p)
          primes.pb(p);
}
vll primes1;
void sieve2(ll l,ll r)
{
	bool isprime[r-l+1];
	fill(isprime,1);
	if(l==1)
	    isprime[0]=false;
	ll base;
	for(ll i=0;primes[i]*primes[i]<=r;i++)
	{
		base = (l/primes[i])*primes[i];
		if(base<l)
		{
			base += primes[i];
		}
		for(long long j=base;j<=r;j+=primes[i])
		{
			isprime[j-l]=false;
		}
		if(base==primes[i]){
			isprime[base-l]=true;
		}
	}
	for(int i=0;i<r-l+1;i++)
	{
		if(isprime[i])
		    primes1.pb(i+l);
	}
}
// void primefactorization(ll x,mll &mp)
// {
//      for(ll i=0;primes[i]*primes[i]<=x;i++)
//     {
//         while(x%primes[i]==0)
//         {
//             mp[primes[i]]++;
//             x/=primes[i];
//         }
//     }
//     if(x!=1)
//     {
//         mp[x]++;
//     }
// }

void primefactorization(ll n,mll &mp)
{
    while(n!=1)
    {
        mp[spf[n]]++;
        n/=spf[n];
    }
}


bool primeornot(ll n)
{
    for(ll i=0;primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            return false;
        }
    }
    return true;
}

void allfactors(vll &v,ll n)
{
    for(ll i=1;i*i<=n;i++)
	{
        if(n%i==0)
        {
            v.pb(i);
            if(i*i!=n)
            {
                v.pb(n/i);
            }
        }
	}
	sort(v.begin(),v.end());
}

ll power(ll a,ll n)
{
 ll res=1;
 while(n)
{
 if(n%2){
    res=( (res%mod) * (a%mod)) % mod;
 }
    a=( (a%mod) * (a%mod) ) % mod;
    n/=2;
}
res%=mod;
return res;
}

ll modInv(ll a){
	return power(a,mod-2)%mod;
}

void modFact()
{
    ll n = maxn;
    ifact=new ll[n+1];
    fact=new ll[n+1];
    fact[0]=fact[1]=1;
    for(int i=2;i<=n;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
    }
    ifact[n]=modInv(fact[n]);
    for(int i=n-1;i>=0;i--)
    {
        ifact[i]=((i+1)*ifact[i+1])%mod;
    }
}

ll ncr(ll n, ll r)
{
    if(n<r || r<0)
        return 0;
    ll ans=fact[n];
    ans*=ifact[r];
    ans%=mod;
    ans*=ifact[n-r];
    ans%=mod;
    return ans;
}

ll npr(ll n, ll r)
{
    if(n<r || r<0)
        return 0;
    ll ans=fact[n];
    ans*=ifact[n-r];
    return ans%mod;
}

ll lcm(ll a,ll b)
{
	ll x=__gcd(a,b);
	a/=x;
	b/=x;
	ll sum=a*b*x;
	return sum;
}

bool ispalindrome(string str,ll l,ll r)
{
    while(l<=r)
    {
        if(str[l]!=str[r])
        return false;
        l++;
        r--;
    }
    return true;
}

ll reversenum(ll n)
{
    ll ans=0;
    while(n)
    {
        ans= (ans*10)+n%10;
        n/=10;
    }
    return ans;
}

void fraction(string &str, ll &num,ll &den) 
{
    ll n = str.length();
    ll count_after_dot = 0;
    bool dot_seen = false;
  
    for (ll i = 0; i < n; i++) 
    { 
        if (str[i] != '.') 
        { 
            num = num*10 + (str[i] - '0'); 
            if (dot_seen == true) 
                count_after_dot++; 
        } 
        else
            dot_seen = true; 
    }
    if (dot_seen == false)
    {
        den=1;
        return;
    }
    ll dem = (ll)pow(10, count_after_dot);
    ll g = __gcd(num, dem);
    num=num/g;
    den = dem/g;
    return; 
}

string tobinary(ll n) 
{
    if (n==0) return "0";
    else if (n==1) return "1";
    else if (n%2 == 0) return tobinary(n/2) + "0";
    else if (n%2 != 0) return tobinary(n/2) + "1";
}

#define countsetbit  __builtin_popcount

ll countbit(ll n) 
{ 
    return (ll)log2(n)+1; 
}

ll setbit(ll n, ll k) 
{ 
    return (n | (1 << (k - 1))); 
}

ll clearbit(ll n, ll k) 
{ 
    return (n & (~(1 << (k - 1)))); 
}

ll togglebit(ll n, ll k) 
{ 
    return (n ^ (1 << (k - 1))); 
}
ll arr[maxn];
ll n;
ll dp[3][maxn];

ll fun(ll pos,ll num,ll s)
{
    if(num==0)
    {
        return 0;
    }
    if(pos>n)
        return INT_MIN;
    if(dp[s][pos]!=llmin)
    {
        return dp[s][pos];
    }
    ll ans1 = arr[pos] + fun(pos+2,num-1,s);
    // cout<<sum<<bl;
    ll ans2 = llmin;
    if(s>0)
    {
       ans2 = fun(pos+1,num,s-1);
    }
    return dp[s][pos] = max(ans1,ans2);
    // cout<<sum<<bl;
    
}


void solve()
{
    
    cin>>n;
    input(arr,0,n-1);
    // print(arr,0,n-1);
    sfor(i,0,2)
    {
        sfor(j,0,n-1)
        {
            dp[i][j]=llmin;
        }
    }
    ll s = (n%2)?2:1;
    ll k=n/2;
    cout<<fun(0,k,s);
    
}

int main(){
	acc;
    ll t=1;
    // cin>>t;
    while(t--)
        solve();


    return 0;
}



