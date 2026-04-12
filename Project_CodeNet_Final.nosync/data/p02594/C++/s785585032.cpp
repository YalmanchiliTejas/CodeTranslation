#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD3 1000000000
#define MOD2 998244353 
float PHI = 1.6180339;
const float  PI_F=3.14159265358979f;
#define MAX 1000 m
#define endl "\n"    
#define manhunt 32 
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define pi 3.1415926535897932384626433
//typedef long long float;
#define int long long
//#define double long double
typedef pair<int, int> pii;
//#define float unsigned long long
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define CHAR_SIZE 26 

int modpow(int x, int n, int m) { if (n == 0) return 1%m; long long u = modpow(x,n/2,m); u = (u*u)%m; if (n%2 == 1) u = (u*x)%m; return u; } 


int add(int x, int y,int m) 
{
	x += y;
	if (x >= m) return x - m;
	return x;
}
int sub(int x, int y) 
{
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int inv(int a, int m = MOD2)
{
	return modpow(a, m - 2, m);
}
int mul(int a, int b,int m) 
{
	return (long long) a * b % m;
}


int nCrModp(int n, int r, int p) 
{ 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 

bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
    if(a.first==b.first)
    return a.second<b.second;
      return (a.first > b.first); 
       //return (a.first-a.second)>(b.first-b.second);
}

vector<int> z_function(string &s)
{
	int n=s.size();
	vector<int> z(n);
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<=r)
			z[i]=min(r-i+1, z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r)
			l=i, r=i+z[i]-1;
	}
	return z;
}

bool isprime(int n) 
{ 
    if (n <= 1)  return false; 
  
    for (int i=2; i*i<=n; i++) 
        if (n%i == 0) 
            return false; 
  
    return true; 
}

void SieveOfEratosthenes(int n, bool isPrime[]) 
{ 
    isPrime[0] = isPrime[1] = false; 
    for (int i=2; i<=n; i++) 
        isPrime[i] = true; 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (isPrime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                isPrime[i] = false; 
        } 
    } 
}


int32_t main()
{
    /* freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); */
    FAST
    cout << fixed << setprecision(16);

    int n;
    cin>>n;
    if(n>=30)
    cout<<"Yes";
    else
    cout<<"No";
    
    
    return 0;
}



