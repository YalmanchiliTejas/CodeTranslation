//-_-Author:: SOURAV BISWAS
//-_-Dept-Electronics & Communication 
//-_-Institution:: Jalpaiguri Government Engineering College
//-_-***********EAT____SLEEP____CODE____REPEAT***************
//_-_PUBG-Ultra$BisWas
//-__Number of leading zeroes: builtin_clz(x)
//_-_Number of trailing zeroes : builtin_ctz(x)
//-_-Number of 1-bits: __builtin_popcount(x)  
#include <bits/stdc++.h> 
using namespace std; 
#define NIL -1  
#define MAX -1e9
#define MIN 1e9
#define ll long long int
#define dd double
#define koto(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
#define fmp(a,x) for(auto &a:x)
#define frv(i,a,b)  for(ll i=a;i<=b;i++)
#define fr0(i,a)   for(ll i=0;i<a;i++)
#define frr(i,a,b) for(ll i=b;i>=a;i--)
#define frr1(i,a)   for(ll i=a-1;i>=0;i--)
#define sa(a,n) sort(a,a+n)
#define sd(a,n) sort(a,a+n,greater<ll>())
#define sva(a) sort(a.begin(),a.end())
#define svd(a) sort(a.begin(),a.end(),greater<ll>())
#define cazz ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define mod (ll)(1000000007)
#define tc(t) int t;cin >>t;while(t--)
#define pb(i) push_back(i)
#define rr return 0
ll mod=1e9+7;
ll const maxn=1e5;
const int INF = 1e9 + 10;
ll add(ll a,ll b){
    return ((a%mod)+(b%mod))%mod;
}
ll mul(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;
}
ll powm(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
ll modinverse(ll a, ll m){
    return powm(a,m-2,m);
}
bool comp(int a, int b)
{
    return (a < b);
}
void divisors(ll n){
    vector<ll>v;
    for (ll i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i)
                v.pb(i);
            else
            v.pb(i);
            v.pb(n/i);
        }
    }
}
bool isPowerOfTwo(ll x) 
{ 
     // First x in the below expression is 
     // for  the case when x is 0  
     return x && (!(x & (x - 1))); 
} 
ll computeXOR(ll n){
    if (n % 4 == 0) 
        return n; 
    if (n % 4 == 1) 
        return 1; 
    if (n % 4 == 2) 
        return n + 1; 
    else
        return 0; 
} 
vector<ll> sieve(ll n) {     
    bool prim[n+1]; 
    memset(prim, true, sizeof(prim)); 
  
    for (ll p=2; p*p<=n; p++) {
        if (prim[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prim[i] = false; 
        } 
    }
    vector<ll>v;
    for(int i=2;i<=n;i++)if(prim[i])v.push_back(i);
    return v; 
}
bool isPrime(ll n){
    if (n <= 1)
        return false;
    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
            
    return true;
}
ll sumofdigits(ll n){
    ll c=0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}
ll lg2(ll n){
	int cnt=0;
	while(n!=1){
		n/=2;
		cnt++;
	}
	return cnt;
}
bool cmp(string a,string b){
	return a.size()<b.size();
}
ll divisor(ll a,ll b){
    return (a%b == 0)? abs(b) : divisor(b,a%b); 
}
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
ll l_p_n_n(ll N){
    //changing all right side bits to 1.
    N = N| (N>>1);
    N = N| (N>>2);
    N = N| (N>>4);
    N = N| (N>>8);
    return (N+1)>>1;

}
string n;
vector<ll>v;
ll d;
ll dp[10005][2][102];
ll fun(ll pos,ll f, ll sum){
    if(pos==v.size()){
        if(sum==0){
            return 1;
        }
        return 0;
    }
    ll ans=0;
    if(dp[pos][f][sum]!=-1)return dp[pos][f][sum];
    ll lmt=9;
    if(f==0)lmt=v[pos];
    for(ll dgt=0;dgt<=lmt;dgt++){
        ll nf=f;
        if(f==0 and dgt<lmt){
            nf=1;
        }
        ans=add(fun(pos+1,nf,(dgt+sum)%d),ans);
    }
    //dp[pos][f][sum]=ans;
    return dp[pos][f][sum]=ans;
    // return ans;
}

ll solve(){
    ll k;
    cin>>n;
    cin>>d;
   // cout<<d<<"\n";
    for(ll i=0;i<n.size();i++)v.push_back(n[i]-'0');
    memset(dp,-1,sizeof(dp));
    ll ans=fun(0,0,0);
    ans-=1;
    if(ans<0)ans+=mod;
    cout<<ans;
}
int main(){
    cazz
        solve();
} 