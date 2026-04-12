//triedodin
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define mem(a, b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define mod1 1000000007
#define mod2 998244353
#define ll long long int
#define ld long double 
#define inf LLONG_MAX
#define endl "\n"
#define F first
#define S second
#define inp(a) int a;cin>>a;
const double pi=acos(-1.0);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //greater<int> can also be used
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define sz(c) (int)c.size()
#define d1(x)            cout<<#x<<"="<<x<<endl;
#define d2(x,y)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define d3(x,y,z)        cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define d4(x,y,z,w)      cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w <<"="<<w<<endl;
#define da(arr,j,n)  for(int i=j;i<n;i++) {cout<<arr[i]<<" "; if(i==n-1)cout<<endl;} 

const  ll MODA =                         1000000007;
// const  int MODA =                     998244353 ;
vector<ll> primefactors    ;            // used by generatePrimeFactors()                                                                                   // ARRAYS/VECTORS
vector<ll> factors         ;            // used by generateFactors()
ll   fact[1025]={}         ;            // used by generateFactorial() & ncr()
bool isPowerTwo(ll x)                   { return (x && !(x & (x - 1))); }                                                                                    // FUNCTIONS
ll   modmul(ll a,ll b)                  { return((a%MODA)*(b%MODA))%MODA;     }
ll   modadd(ll a,ll b)                  { return((a%MODA)+(b%MODA)+MODA)%MODA;}
ll   modsub(ll a,ll b)                  { return((a%MODA)-(b%MODA)+MODA)%MODA;}
bool isSubstring(string s1, string s2)  { if (s1.find(s2) != string::npos) return true; else return false; }
void generateFactorial(ll n)            { fact[0] = 1; for(ll i = 1; i <= n; i++)   fact[i] = (i* 1ll * fact[i - 1]) ; }
void generateFactorialMOD(ll n)         { fact[0] = 1; for(ll i = 1; i <= n; i++)   fact[i] = (i* 1ll * fact[i - 1]) % MODA; }
bool isPrime(ll n)                      { if(n<2) return false; for(ll i=2;i*i<=n;i++) if(n%i==0) return false; return true; } //O(sqrt(n))
ll   power(ll a, ll b)                  {   ll res=1; while(b) {    if(b&1) res=(res*a); a=(a*a);   b>>=1;  }   return res; }
ll   powermod(ll a, ll b)               {   ll res=1; while(b) {    if(b&1) res=(res*a)%MODA; a=(a*a)%MODA;     b>>=1;  }   return res; }
ll   modi (ll a)                        { ll m=MODA,s=1,p=0;  while(a>1)  {  ll q=a/m,t=m;  m=a%m; a=t; t=p; p=s-q*p; s=t;  } return s>=0 ? s :s+MODA; }
void generatePrimeFactors(ll n)         { primefactors.clear(); for(ll i=2;i*i<=n;i++) { if(n%i==0) { primefactors.pb(i); while(n%i==0)  n=n/i; } } if(n!=1)   primefactors.pb(n); }
ll   ncr(ll n, ll r)                    { if(r==0)return 1;  fact[0]=1; for(int i=1 ; i<=n; i++) fact[i] = fact[i-1]*i%MODA;   return (fact[n]* modi(fact[r]) % MODA *  modi(fact[n-r]) % MODA) % MODA; }
void generateFactors(ll n)              { factors.clear(); for(ll i=2;i*i<=n;i++){ if(n%i==0) { factors.pb(i); if(n/i!=i)factors.pb(n/i); }} factors.pb(1); factors.pb(n); sort(factors.begin(),factors.end()); }
ld   Logn(ld n, ld r)                   { return log(n) / log(r); }  

///////////////////////////////////
const int Nmax = 1000005;
    



////////////////////////////////////



void solve(){

   int n;
   cin >> n;

   if(n>=30){
    cout << "Yes" << endl;
   }
   else{
    cout << "No" << endl;
   }
    }

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
      ios_base::sync_with_stdio(false); cin.tie(0);
   

      int t= 1;
        //cin >> t;

        while(t--){
            solve();
        }

        printclock;
  

  }

/////////////////////////////
//try to bring as much symmetry as possible
//just check for integer overflow
//add MOD value when you substract two numbers


/////////////////////////////