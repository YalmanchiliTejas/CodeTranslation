#include<bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define int         ll int
#define float       double
#define	endl		'\n'
#define maxpq       priority_queue<ll>
#define minpq       priority_queue<ll, vector<ll>, greater<ll> >
#define mii         map<int,int>
#define msi         map<string,int>
#define mis         map< int, string>
#define mpi         map<pair< int, int>, int>
#define pii         pair< int, int>
#define vi          vector< int>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define EPS         1e-9
#define INF         1e18
#define PI          3.14159265358979323846
#define MAXI        1000000
#define what_is(x)  cerr << #x << " is " << x << endl;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
#define N 100005
int modexp(int x,int n,int mod){
	x%=mod;
	int res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n/=2;
	}
	return res;
}
int modInverse(int n, int p)
{ 
    return modexp(n, p - 2, p); 
} 
int nCr(int n,int r, int p) 
{ 
    if (r == 0) 
        return 1; 
    int fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 
signed main()
{
	fast;
	int t=1;
	//cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n>=30) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
   }
   return 0;
}