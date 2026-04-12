#include<bits/stdc++.h>
using namespace std;
#define	ll				long long

#define	mod 			1000000007
#define	inf 			1000000000000000
#define infty			1000000000000000000LL
#define	md				998244353
#define	PI				acos(-1.0)
#define	endl 			"\n"
#define	rr				return
#define	br				cout<<"\n";
long long prime[1000000];

void sieve()
{
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i<1000000;i++)
		prime[i]=1;

	for(int i=2;i*i<1000000;i++)
		if(prime[i]==1)
			for(int j=i*i;j<1000000;j+=i)
				prime[j]=0;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i <= floor(sqrt(n)); i++)
        if (n % i == 0)
            return false;

    return true;
}

int factorial(int n)
{
    int f=1;
    for(int i = 1;i<=n ; i++)
        f = (f*i)%mod;
    return f;
}

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

int fastExponentiation(int n, int x, int modulo)
{
	int res = 1;
	while(x > 0)
       {
          if(x & 1)
          res = (res*n) % modulo;
          x = x >> 1;
          n = (n * n) % modulo;
       }
       return res;
}

int power(int n , int p )
{
	if(p==0)
	   return 1;

	 int res = power((n*n)%mod,p/2);
	 if(p%2==1)
	   res = (n*res)%mod;

	   	 return res;
}

bool isPowerOfTwo(int n)
{
   	return n && (!(n&(n-1)));
}

bool isSet(int n,int i)
{
	// To check if ith bit is set or not in binary representation of n
   	return n & (1 << i);
}

bool valid_coordinate(ll x,ll y,ll n,ll m)
{
    if(x<0 || y<0)
       return false;

   	else if(x>=n || y>=m)
       return false;

   	else
   		return true;
}

int sod(int n)
{
	int sum=0;
	while(n)
	{
		sum+=(n%10);
		n/=10;
	}
	return sum;
}



void solve()
{
	string s;
	cin>>s;
	int a,b;
	a=b=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A')
		a++;
		if(s[i]=='B')
		b++;
	}
	if(a>0&&b>0)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}

int32_t main()
{

	//int t; cin>>t; while(t--)
	solve();

	return 0;
}
