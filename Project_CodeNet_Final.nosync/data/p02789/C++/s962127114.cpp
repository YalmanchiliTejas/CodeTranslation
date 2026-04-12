#include<bits/stdc++.h>
using namespace std;


#define mod 1000000007
#define ull unsigned long long int
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
/* TYPE DEFINITIONS */
typedef     long long int        ll;
typedef     vector<ll>     vi;
typedef     pair<ll,ll>   pi;
 
 
 
/* MATH */
bool isPrime(ull n) 
{ 
    if (n <= 1)  return true; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ull i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
 
ll pow(ll a,ll b,ll m)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

ll ncr(int n, int k)  
{  
	if(k>n)return 0;
    ll res = 1;  
    if ( k > n - k )  
        k = n - k;  
    for (int i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
} 
  
//
/* MACROS */
 
#define  all(A)         (A).begin() , (A).end()
#define  arrall(A,n)    (A),((A)+(n))
#define  rall(A)        (A).rbegin() , (A).rend()
#define  sz(A)          (int)(A).size()
#define  pb             push_back
#define  ppb            pop_back
#define  mp             make_pair
#define  ln(X)          (int)(X).length()
#define  square(X)      ((X)*(X))
#define  cube(X)        ((X)*(X)*(X))
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)    for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) 
#define  deb(x)       cout << '>' << #x << ':' << x << endl;

void  solve()
{
	int a,b;
	cin>>a>>b;
	if(a==b)cout<<"Yes";
	else cout<<"No";
}


int main()
{
 
    FastIO;
    ll t=1;
   	//cin>>t;
    while(t--)
    {
        solve();
    }
}