
// Problem : A - Air Conditioner
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define flush  cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define fill(w,t) memset(w,t,sizeof(w))
#define google cout<<"Case #"<<countu<<": "
#define S(t) (ll)t.size()
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
#define mk make_pair
#define pll pair<ll,ll>
#define pldb pair<ldb,ldb>
#define fi first
#define se second
#define vull vector<ull>
#define vll vector<ll>
#define vldb vector<ldb>
#define vpll vector< pll >
#define vpldb vector< pldb >
#define pqmin priority_queue<ll,vector<ll>,greater<ll> >     //minheap
#define pq priority_queue<ll>                                //maxheap ll
#define pqpll priority_queue<pll>                            //maxheap pll
#define pqpllmin priority_queue<pll, vector<pll>, greater<pll> >   //minheap pll
#define mll map<ll,ll>
#define mldb map<ldb,ldb>
#define umll unordered_map<ll,ll>
#define sll set<ll>
#define usll unordered_set<ll>
#define sfor(i,a,b) for (ll i = (a); i <= (b); ++i)
#define rfor(i,b,a) for (ll i = (b); i >= (a); --i)
const ll mod = 1e9+7;
const ll maxn = 1e6+1;
const ll llmax = (1ll<<60);
const int intmax = (1<<30);
const ldb PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899863;
vll fact , ifact;
vll primes;
vll spf; 
void sieve() 
{
    spf.resize(maxn+1,0);
    // fill(spf,0);
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
void primefactorll(ll x,mll &mp)
{
     for(ll i=0;primes[i]*primes[i]<=x;i++)
    {
        while(x%primes[i]==0)
        {
            mp[primes[i]]++;
            x/=primes[i];
        }
    }
    if(x!=1)
    {
        mp[x]++;
    }
}
void primefactor(ll n,mll &mp)
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
		if(n%2)
		{
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
    ifact.resize(n+1);
    fact.resize(n+1);
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

string convert_to_bit(ll a,int bit)
{
	string s;
	while(a>0){
		s+=(a%2)+48;
		a/=2;
	}
	while(s.size()<bit)
		s+='0';
	reverse(s.begin(),s.end());
	return s;
}


ll bit_to_decimal(string &num)
{
	// string num = n; 
    ll dec_value = 0; 
    ll base = 1;   
    ll len = num.length(); 
    for (ll i = len - 1; i >= 0; i--) 
    { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    }   
    return dec_value; 
}

ll todecimal(string str)
{
	return stoll(str, nullptr, 10);
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
    return (n | (1 << (k - 1)));     // index start from 1
}

ll clearbit(ll n, ll k) 
{ 
    return (n & (~(1 << (k - 1)))); 
}

ll togglebit(ll n, ll k) 
{ 
    return (n ^ (1 << (k - 1))); 
}

ll findpivot(vll &arr,ll low,ll high)
{
	while(low < high) 
	{ 
		int mid = low + (high - low)/2; 
		if (arr[mid] == arr[high]) 
			high--; 
		else if(arr[mid] > arr[high]) 
			low = mid + 1; 
		else
			high = mid; 
	} 
	return high;
}


// ifstream  i_data("data.in");
// ofstream  o_data("data.out");
// #define cin  i_data
// #define cout o_data
//ifstream cin("b_read_on.txt"); ofstream cout("output3.txt");
//Use (<<) for multiplication
//Use (>>) for division
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed;cerr.tie(NULL);
// find_by_order -> value at index
// order_of_key -> index of value
// while using (1<<i) use ((ll)1<<(ll)i) 
// in Floyd-Warshall Algo, k is outer loop 
// If an element was not initially in map and if asked mp[a],the element gets inserted 
// a%=mod take a lot of time... try to use it minimum and use memset as it reduces a lot of time usage...use if(a>=mod) a%=mod
//cout<<(double) can be harmful , always use printf(%.9llf)...take scanf("%lf",&p[i][j]) as input , not llf;
//use s.erase(it++) for erasing iterator and then moving to the next one
//never use adj.resize(n) as value is persistent, always erase
//use __builtin_popcountll() for ll
// no of prime numbers in range : (70,19) , (1000,168) , (100000,1229) , (sqrt(10^9),3409) ;
//always check the use of segment tree using bottom-up dp
//__gcd(0,0) gives runtime error
//power(a,b) == power(a,b%phi(a)) Fermet's Theorem
//never use "=" operator in compare function
//For checking odd cycles, check bipartite

void solve(ll countu)
{ 
    ll t;
    cin>>t;
    if(t>=30)
    {
    	cout<<"Yes";
    }
    else
    {
    	cout<<"No";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));
    
    
     // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);



    ll t=1;
    // cin>>t;
    sfor(i,1,t)
        solve(i);


    return 0;
}





