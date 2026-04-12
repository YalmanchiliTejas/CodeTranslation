/**
       **********    ************
	  Author : Avi J Patel
	  University : DAIICT
       **********    ************
**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define pf push_front
#define mp make_pair 
#define mt make_tuple
#define ff first
#define ss second
#define si size()
#define MOD 1000000007
#define Mod 998244353
#define large 10000000000000001
#define For(i,m,n) for(long long i=m;i<n;i++)
#define st(x) sort(x.begin(),x.end())
#define re(x,i) reverse(x.begin()+i,x.end())
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    if(a.ss < b.ss) return true; 
	else return false;
}
bool sortbyboth(const pair<int,int> &a, const pair<int,int> &b)
{
	if(a.ff<b.ff) return true;
	else if(a.ff==b.ff) return a.ss<b.ss;
	else return false;
} 
bool sortff_resortss(const pair<int,int> &a, const pair<int,int> &b)
{
	if(a.ff<b.ff) return true;
	else if(a.ff==b.ff) return a.ss>b.ss;
	else return false;
}
bool sortbystring(const string &a, const string &b)
{
	string c=a+b;
	string d=b+a;
	if(c>=d) return true;
	else return false;
}
class CompareDist
{
	public:
	    bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b) 
		{
	        if(a.ff<b.ff) return true;
	        else if(a.ff==b.ff) return a.ss.ff>b.ss.ff;
	        else return false;
	    }
};

ll modi(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 
ll Logn(ll  n, ll r) 
{ 
    return (n > r - 1) ? 1 + Logn(n / r, r) : 0; 
} 

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
    x = x % p;  // Update x if it is more than or 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 

ll modinv(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
ll ncr(ll n, ll r, ll p) 
{ 
   if (r==0) 
      return 1; 
    int n1=n;
    ll fac[n1+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modinv(fac[r], p) % p * 
            modinv(fac[n-r], p) % p) % p; 
} 
#define MAXN   10000001 
int spf[MAXN]; 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

bool isPowerOfTwo(int x)
{	//check whether number is power of 2.
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}

int count_one (int n) //number of set bits.
{
	int count=0;
    while( n )
    {
    n = n&(n-1);
       count++;
    }
    return count;
}
int main()
{
	FAST
	int t=1;
//	cin>>t;
	while(t--)
	{	
		int x;
		cin>>x;
		if(x>=30)
		{
			cout<<"Yes";
		}
		else
		cout<<"No";
	}
    return 0;
}
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

