#include <bits/stdc++.h> 
using namespace std; 
#include <stack>
#define ll long long 
const ll INF=1000000007;
#define vecpair vector<pair <ll,ll> >
#define pb push_back
#define mp make_pair
#define vel vector<ll>
#define endl "\n"
#define forl for(int i=0;i<n;i++)
const ll MAXN=1000001;
bool prime[1000001];
void SieveOfEratosthenes() 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true.  
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=1000000; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=1000000; i += p) 
                prime[i] = false; 
        } 
    } 
  
    
} 
ll bs(vel a,ll x,ll n){
	int l=0;
	int h=n-1;
	int m;
	while(l<=h){
		m=(l+h)/2;
		if(a[m]>=x) h=m-1;
		else if(a[m]<x) l=m+1;
		}
		if(a[m]>=x) m--;
		return m;
}

ll power(ll x, ll y)  
{  
	
    ll res = 1;     // Initialize result  
  
    // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) ;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) ;  
    }  
    return res;  
}  

ll mex(vel a,int n){
	sort(a.begin(),a.end());
	int j=a[0];
	if(j!=0) return 0;
	else{
		for(int i=1;i<n;i++){
				if(a[i]!=a[i-1]){
					if(a[i]!=a[i-1]+1){
						return j+1;
						}else j++;
					}
			}
			return j+1;
		}
}

int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

ll c(ll m,ll n){
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*(m-i+1))/i;
		}
		return ans;
}

ll modInverse(ll a,ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

ll pc(ll n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return 0;
		}	
		return 1;
}

ll lexo(string a,string b){
ll n=a.length();
for(int i=0;i<n;i++){
	if(a[i]<b[i]) return 1;
	else if(b[i]<a[i]) return 0;
}
	return 0;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll test;
test=1;
while(test--){			
ll n;
cin>>n;
ll a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
	}
	ll sum=0;
	for(int i=0;i<n;i++){
		sum=(sum+a[i]);
		}
		ll s[n];
		for(int i=0;i<n;i++){
			s[i]=(sum-a[i])%INF;
			sum=(sum-a[i]);
			}
		ll ans=0;
		for(int i=0;i<n;i++){
			ans=(ans+(a[i]*(s[i]))%INF)%INF;
			}
			cout<<ans<<endl;
}
}
